#include"Equipment.h"
#include"Simulator.h"
#include"Exceptions.h"

vector<Equipment*> nodes;
vector<Equipment*> hubs;
vector<Equipment*> routers;
vector<Equipment*> switches;
vector<Equipment*>::iterator it;

LST_ITERATOR lstit;
MAP_ITERATOR mapit;

MAP getMAP(QVariant value){ return value.toMap().toStdMap(); }
LST getLST(QVariant value){ return value.toList().toVector().toStdVector(); }
STR getSTR(QVariant value){ return value.toString().toStdString(); }

Simulator::Simulator(){}
Simulator::~Simulator(){}

int Simulator::simulate()
{
	string input = "";
	cout << "Bem-vindo ao NexSim 1.0. Digite help para ajuda." << endl; 
	this->help();
	forever{
		cout << "Digite um comando: ";
		getline(cin,input); 
		this->parse_command(input);
	}
	return 0;
}

void Simulator::help()
{
	cout << "Comandos para execucao:\n\n"
	"create router - Comando para criar roteadores na topologia.\n"
	"create switch - Comando para criar switches na topologia.\n"
	"create hub - Comando para criar hubs na topologia.\n"
	"create node - Comando para criar nodos na topologia.\n"
	"read topology file.json - Comando para ler um arquivo e gerar a topologia.\n"
	"all - Mostra todos os dispositivos adicionados no simulador.\n"
	"nodes - Mostra todos os nodos adicionados no simulador.\n"
	"routers - Mostra todos os roteadores adicionados no simulador.\n"
	"switches - Mostra todos os switches adicionados no simulador.\n"
	"hubs - Mostra todos os hubs adicionados no simulador.\n"
	"select router n - Seleciona o Router n para executar no simulador.\n"
	"select switch n - Seleciona o Switch n para executar no simulador.\n"
	"select hub n - Seleciona o Hub n para executar no simulador.\n"
	"select node n - Seleciona o Node n para executar no simulador.\n"
	"\n\n";
}

void Simulator::parse_command(string cmd)
{
	try{
		if(contains(cmd,"create")){
			if(contains(cmd,"hub")) this->create_hub();
			else if(contains(cmd,"switch")) this->create_switch();
			else if(contains(cmd,"router")) this->create_router();
			else if(contains(cmd,"node")) this->create_node();
			else throw CommandException();
		}else if(contains(cmd,"select")){
			if(contains(cmd,"hub",10)) this->select<Hub,Equipment>("Hub",substring(cmd,11),hubs);
			else if(contains(cmd,"switch",13)) this->select<Switch,Equipment>("Switch",substring(cmd,14),switches);
			else if(contains(cmd,"router",13)) this->select<Router,Equipment>("Router",substring(cmd,14),routers);
			else if(contains(cmd,"node",11)) this->select<Node,Equipment>("Node",substring(cmd,12),nodes);
			else throw CommandException();
		}else if(contains(cmd,"all")){
			this->show<Node,Equipment>("Nodes",nodes);
			this->show<Router,Equipment>("Routers",routers);
			this->show<Switch,Equipment>("Switches",switches);
			this->show<Hub,Equipment>("Hubs",hubs);
		}
		else if(contains(cmd,"read topology",13)) read_topology(substring(cmd,14));
		else if(contains(cmd,"nodes")) this->show<Node,Equipment>("Nodes",nodes);
		else if(contains(cmd,"routers")) this->show<Router,Equipment>("Routers",routers);
		else if(contains(cmd,"switches")) this->show<Switch,Equipment>("Switches",switches);
		else if(contains(cmd,"hubs")) this->show<Hub,Equipment>("Hubs",hubs);
		else if(contains(cmd,"help")) this->help();
		else if(contains(cmd,"exit")) this->exit_simulator();
		else throw CommandException();
	}catch(exception &e){ cout << e.what() << endl; return; }
}

void Simulator::exit_simulator()
{
	string input = "";
	for(it = nodes.begin(); it != nodes.end(); it++) delete *it;
	for(it = routers.begin(); it != routers.end(); it++) delete *it;
	for(it = switches.begin(); it != switches.end(); it++) delete *it;
	for(it = hubs.begin(); it != hubs.end(); it++) delete *it;
	cout << "Terminado. Pressione enter para sair." << endl; 
	getline(cin,input); exit(0);
}

template<typename F,typename S>
void Simulator::connect_interface(F* selected, S* connector)
{
	string connector_address,selected_address;

	Interface* interf = new Interface();
	map<string,Interface*> interfaces = connector->get_interfaces();
	interf->identifier = interfaces.size()+1;
	interf->con = (void*) selected;
	interf->type = typeid(F).name();

	Interface* sinterf = new Interface();
	map<string,Interface*> sinterfaces = selected->get_interfaces();
	sinterf->identifier = sinterfaces.size()+1;
	sinterf->con = (void*) connector;
	sinterf->type = typeid(S).name();

	if(contains(interf->type,"Hub") || contains(interf->type,"Switch")) 
		connector_address = connector->get_mac_address();
	else connector_address = connector->get_ip_address();
	if(contains(sinterf->type,"Hub") || contains(sinterf->type,"Switch")) 
		selected_address = selected->get_mac_address();
	else selected_address = selected->get_ip_address();

	connector->add_interface(selected_address,interf);
	selected->add_interface(connector_address,sinterf);
	QObject::connect(selected,&F::packet_sended,(S*)connector,&S::packet_receive);
	QObject::connect((S*)connector,&S::packet_sended,selected,&F::packet_receive);
	connector->start();
	cout << "Dispositivo conectado: " << (*connector) << endl;
}

template<typename F, typename S> 
void Simulator::select(string equip_str, string number_str, vector<S*> &equips)
{
	//Seleciona o dispositivo e ativa para uso.
	int connect,number = 0;
	string input = "";
	F* selected = NULL;
	istringstream buffer(number_str);
	buffer >> number;
	try{
		if(number < 1) throw LimitException();
		else if(number > equips.size()) throw LimitException();
		selected = (F*) equips.at(number-1);
		cout << equip_str << " " << number << " selecionado" << endl;
	}catch(exception& e){ cout << e.what() << endl; return; }
	if(!selected->isRunning()) selected->start();
	cout << "Console do " << equip_str << " " << number << " iniciado." << endl;
	selected->help();
	forever{
		cout << "(" << equip_str << " " << number << ") Digite um comando: "; getline(cin,input); 
		if(contains(input,"connect",11)){
			istringstream buffer_connect(substring(input,(int)input.size()-1));
			connect = 0; buffer_connect >> connect;
			if(contains(input,"hub"))			this->connect_interface<F,Hub>(selected,(Hub*)hubs.at(connect-1));
			else if(contains(input,"switch"))	this->connect_interface<F,Switch>(selected,(Switch*)switches.at(connect-1));
			else if(contains(input,"router"))	this->connect_interface<F,Router>(selected,(Router*)routers.at(connect-1));
			else if(contains(input,"node"))		this->connect_interface<F,Node>(selected,(Node*)nodes.at(connect-1));
		}
		else if(!selected->parse_command(input)) break;
	}
}

template<typename F, typename S>
void Simulator::show(string name, vector<S*> &equips)
{
	//Exibe determinado tipo de dispositivo disponivel no simulador
	cout << endl << name << " disponiveis no simulador: " << endl;
	for(it = equips.begin(); it != equips.end(); it++) cout << (*(F*)(*it)) << endl;
}

void Simulator::read_topology(string name)
{
	if(name.size() < 6) name = "topology.json";
	emit this->send_namefile(name);
}

void Simulator::create_hub(LST* lst)
{
	Equipment* hub;
	string hub_name;
	if(lst != NULL){
		for(lstit = lst->begin(); lstit != lst->end(); lstit++){
			//Cria varios hubs a partir de uma lista
			hub_name = getSTR(*lstit);
			hub = new Hub(hub_name); hubs.push_back(hub);
			cout << hub_name << " criado no simulador." << endl;
		}
	}else{
		//Cria apenas um hub quando nao ha lista
		ss.str(string()); ss << "Hub " << hubs.size()+1; hub_name = ss.str();
		hub = new Hub(hub_name); hubs.push_back(hub);
		cout << hub_name << " criado no simulador." << endl;
	}
}

void Simulator::create_switch(LST* lst)
{
	Equipment* swtch;
	string switch_name;
	if(lst != NULL){
		for(lstit = lst->begin(); lstit != lst->end(); lstit++){
			//Cria varios switches a partir de uma lista
			switch_name = getSTR(*lstit);
			swtch = new Switch(switch_name); switches.push_back(swtch);
			cout << switch_name << " criado no simulador." << endl;
		}
	}else{
		//Cria apenas um switch quando nao ha lista
		ss.str(string()); ss << "Switch " << switches.size()+1; switch_name = ss.str();
		swtch = new Switch(switch_name); switches.push_back(swtch);
		cout << switch_name	<< " criado no simulador." << endl;
	}
}

void Simulator::create_router(MAP* map)
{
	int n_interfaces = 4;
	Equipment* router;
	string router_name;
	string router_address;
	if(map != NULL){
		for(mapit = map->begin(); mapit != map->end(); mapit++){
			//Cria varios routers a partir de um mapa
			router_name = mapit->first.toStdString();
			router_address = getSTR(getMAP(mapit->second)["MAC"]);
			n_interfaces = getMAP(mapit->second)["IFS"].toInt();
			router = new Router(router_name,router_address,n_interfaces); 
			routers.push_back(router);
			cout << router_name << " criado no simulador." << endl;
		}
	}else{
		//Cria apenas um router quando nao ha mapa
		ss.str(string()); ss << "Router " << routers.size()+1; router_name = ss.str();	
		ss.str(string()); ss << "00:00:00:00:" << setfill('0') << setw(2) << routers.size()+1 << ":FF";	router_address = ss.str(); 
		router = new Router(router_name,router_address,n_interfaces); 
		routers.push_back(router);
		cout << router_name << " criado no simulador." << endl;
	}
}

void Simulator::create_node(MAP* map)
{
	Equipment* node;
	string node_name;
	string node_address;
	if(map != NULL){
		for(mapit = map->begin(); mapit != map->end(); mapit++){
			//Cria varios nodes a partir de um mapa
			node_name = mapit->first.toStdString();
			node_address = getSTR(mapit->second);
			node = new Node(node_name,node_address);
			nodes.push_back(node);
			cout << node_name << " criado no simulador." << endl;
		}
	}else{
		//Cria apenas um node quando nao ha mapa
		ss.str(string()); ss << "Node " << nodes.size()+1; node_name = ss.str();	
		ss.str(string()); ss << "00:00:00:00:" << setfill('0') << setw(2) << routers.size()+1 << ":EE";	node_address = ss.str(); 
		node = new Node(node_name,node_address);
		nodes.push_back(node);
		cout << node_name << " criado no simulador." << endl;
	}
}