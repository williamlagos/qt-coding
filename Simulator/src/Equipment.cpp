#include"Equipment.h"
#include"Exceptions.h"

bool contains(string name, string str){ return name.find(str) != string::npos; }
bool contains(string name, string str, int delim){ return (name.find(str) != string::npos) && name.size() > delim; }
string substring(string name, int delim){ return name.substr(delim,name.size()-delim); }

Equipment::Equipment(string name)
{
	this->name = name;
	this->activated = false;
	this->arp_packet = new PACKET();
	this->icmp_packet = new PACKET();
	this->icmp_packet->ipv4 = new IPv4();
	this->icmp_packet->ipv4->timetolive = NULL;
}

bool Equipment::parse_command(string cmd)
{
	try{
		if(contains(cmd,"set name",8)) this->name = substring(cmd,9);
		else if(contains(cmd,"get name")) cout << this->name << endl;
		else if(contains(cmd,"show con")) this->show_connections();
		else if(contains(cmd,"help")) this->help();
		else if(contains(cmd,"exit")) return false;
		else throw CommandException();
	}catch(exception &e){ cout << e.what() << endl; }
	return true;
}

void Equipment::help()
{
	cout << "Comandos para execucao no console do " << name << ":\n\n"
	"set name n - Escreve um novo nome n para o " << name << ".\n"
	"get name - Imprime o nome atual para o " << name << ".\n"
	"show con - Imprime as conexoes atuais com outros equipamentos.\n"
	"exit - Sai do console e volta para o simulador.\n"
	"\n\n";
}

Equipment::~Equipment(){ 
	this->activated = false;
	this->log.close(); 
}

void Equipment::run()
{
	this->activated = true; 
	this->start_writer(); 
	//forever{ if(!this->activated) break; }
}

void Equipment::show_connections()
{
	string type = "";
	Interface* interf = NULL;
	for(mapit = interfaces.begin(); mapit != interfaces.end(); mapit++){
		interf = mapit->second; type = interf->type; 
		cout << endl << "Dispositivo conectado: ";
		if(contains(type,"Hub"))		 cout << *((Hub*) interf->con);
		else if(contains(type,"Node"))	 cout << *((Node*) interf->con);
		else if(contains(type,"Router")) cout << *((Router*) interf->con); 
		else if(contains(type,"Switch")) cout << *((Switch*) interf->con);
		cout << endl << "ID da interface: " << interf->identifier << endl;
	}
}

void Equipment::start_writer()
{
	stringstream ss;
	ss << this->name << ".txt";
	log.open(ss.str());
}

void Equipment::write(string message,time_t time){ 
	log << "Tempo utilizado: " << time << endl << message << "\n"; 
}

void Equipment::add_interface(string address,Interface* interf){ this->interfaces[address] = interf; }

Hub::Hub(string name):Equipment(name){}

void Hub::packet_receive(void* packet)
{
	time_t timestamp = time(0);
	stringstream ss;
	PACKET* pkt = (PACKET*) packet;
	ss << "Trafego de pacotes no " << name << ":\n" << (*pkt) << endl; write(ss.str(),time(0)-timestamp); 
	emit packet_sended((packet));
}

Switch::Switch(string name):Equipment(name){}

void Switch::addto_mac_table(string address, Interface* interf){ switch_table[address] = interf; }

void Switch::packet_receive(void* packet)
{
	time_t timestamp = time(0);
	stringstream ss;
	string type = "";
	CONNECTOR conn = NULL;
	PACKET* pkt = (PACKET*) packet;
	string mac_destination = pkt->eth->destination;
	if(contains(pkt->eth->destination,"FF:FF:FF:FF:FF:FF"))	emit packet_sended((packet));
	for(mapit = interfaces.begin(); mapit != interfaces.end(); mapit++){
		string mac_source = mapit->first;
		if(contains(mac_source,mac_destination)){
			conn = mapit->second->con;
			type = mapit->second->type;
			break;
		}
	}
	ss << "Trafego de pacotes no " << name << ":\n" << (*pkt) << endl; write(ss.str(),time(0)-timestamp);
	if(conn != NULL){
		if(contains(type,"Hub")) ((Hub*)conn)->packet_receive((void*)pkt);
		else if(contains(type,"Switch")) ((Hub*)conn)->packet_receive((void*)pkt);
		else if(contains(type,"Router")) ((Router*)conn)->packet_receive((void*)pkt);
		else if(contains(type,"Node")) ((Node*)conn)->packet_receive((void*)pkt);
	}
}

bool Switch::parse_command(string cmd)
{
	try{
		if(contains(cmd,"set name",8)) this->name = substring(cmd,9);
		else if(contains(cmd,"get name")) cout << this->name << endl;
		else if(contains(cmd,"show con")) this->show_connections();
		else if(contains(cmd,"show table")) this->show_mac_table();
		else if(contains(cmd,"clear table")) switch_table.clear();
		else if(contains(cmd,"help")) this->help();
		else if(contains(cmd,"exit")) return false;
		else throw CommandException();
	}catch(exception &e){ cout << e.what() << endl; }
	return true;
}

void Switch::help()
{
	cout << "Comandos para execucao no console do Switch:\n\n"
	"set name n - Escreve um novo nome n para o switch.\n"
	"get name - Imprime o nome atual para o switch.\n"
	"show con - Imprime as conexoes atuais com outros equipamentos.\n"
	"show table - Mostra a tabela de enlaces do switch.\n"
	"clear table - Mostra a tabela de enlaces do switch.\n"
	"exit - Sai do console e volta para o simulador.\n"
	"\n\n";
}

void Switch::show_mac_table()
{
	cout << "Tabela do " << this->name << ": " << endl;
	for(mapit = switch_table.begin(); mapit != switch_table.end(); mapit++){
		CONNECTOR c = mapit->second->con;
		string type = mapit->second->type;
		if(contains(type,"Node")) cout << mapit->first << ": " << *((Node*)c);
		else if(contains(type,"Router")) cout << mapit->first << ": " << *((Router*)c);
		else if(contains(type,"Switch")) cout << mapit->first << ": " << *((Switch*)c);
		else if(contains(type,"Hub")) cout << mapit->first << ": " << *((Hub*)c);
	}
}

Router::Router(string name, string mac_address, int n_interfaces):Node(name,mac_address)
{
	this->mac_address = mac_address;
}

void Router::packet_receive(void* packet)
{
	time_t timestamp = time(0);
	stringstream ss;
	string ip_source,ip_destination,type = "";
	CONNECTOR conn = NULL;
	PACKET* pkt = (PACKET*) packet;
	if(pkt->ipv4 != NULL){
		ip_source = pkt->ipv4->ip_source;
		if(contains(pkt->ipv4->ip_destination,"255")) emit packet_sended((packet));
		for(mapit = interfaces.begin(); mapit != interfaces.end(); mapit++){
			ip_destination = mapit->first;
			if(contains(ip_source,ip_destination)){
				conn = mapit->second->con;
				type = mapit->second->type;
				break;
			}
		}
	}
	ss << "Trafego de pacotes no " << name << ":\n" << (*pkt) << endl; this->write(ss.str(),time(0)-timestamp);
	ICMPv4* icmp = pkt->icmpv4;
	//Recebimento de ICMPv4 request e reply
	if(icmp != NULL){
		if(contains(pkt->ipv4->ip_destination,this->ip_address)){
			if(icmp->type == ECHO_REQUEST) this->icmp_echo_reply((PACKET*)packet);
			else if(icmp->type == INFO_REQUEST) this->icmp_info_request((PACKET*)packet,pkt->ipv4->ip_destination);
		}else{
			//Repassagem
		}
	}

	if(conn != NULL){
		//Roteamento direto, interconectado diretamente ao roteador
		if(contains(type,"Hub")) ((Hub*)conn)->packet_receive((void*)pkt);
		else if(contains(type,"Switch")) ((Switch*)conn)->packet_receive((void*)pkt);
		else if(contains(type,"Node")) ((Node*)conn)->packet_receive((void*)pkt);
	}else{
		//Segue a tabela de tabela de roteamento
		conn = NULL;
		for(rtit = routing_table.begin(); rtit != routing_table.end(); rtit++){
			if(contains(rtit->first,ip_destination)){
				conn = rtit->second->interf->con;
				type = rtit->second->interf->type;
				break;
			}
		}
		if(conn != NULL){
			if(contains(type,"Hub")) ((Hub*)conn)->packet_receive((void*)pkt);
			else if(contains(type,"Switch")) ((Switch*)conn)->packet_receive((void*)pkt);
			else if(contains(type,"Router")) ((Router*)conn)->packet_receive((void*)pkt);
			else if(contains(type,"Node")) ((Node*)conn)->packet_receive((void*)pkt);
		}
	}
}

bool Router::parse_command(string cmd)
{
	try{
		if(contains(cmd,"set")){
			if(contains(cmd,"name",8)) this->name = substring(cmd,9);
			else if(contains(cmd,"mac",7)) this->mac_address = substring(cmd,8);
			else if(contains(cmd,"mask",8)) this->address_mask = substring(cmd,9);
			else if(contains(cmd,"ip",6)) this->ip_address = substring(cmd,7);
			else throw CommandException();
		}else if(contains(cmd,"get")){
			if(contains(cmd,"name")) cout << this->name << endl;
			else if(contains(cmd,"mac")) cout << this->mac_address << endl;
			else if(contains(cmd,"mask")) cout << this->address_mask << endl;
			else if(contains(cmd,"ip")) cout << this->ip_address << endl;
			else throw CommandException();
		}
		else if(contains(cmd,"show con")) this->show_connections();
		else if(contains(cmd,"add route")) this->addto_routing_table(substring(cmd,10));
		else if(contains(cmd,"del route")) this->remfrom_routing_table(substring(cmd,10));
		else if(contains(cmd,"show table")) this->show_routing_table();
		else if(contains(cmd,"clear table")) routing_table.clear();
		else if(contains(cmd,"help")) this->help();
		else if(contains(cmd,"exit")) return false;
		else throw CommandException();
	}catch(exception &e){ cout << e.what() << endl; }
	return true;
}

void Router::help()
{
	cout << "Comandos para execucao no console do Router:\n\n"
	"set name n - Escreve um novo nome n para o Router.\n"
	"get name - Imprime o nome atual para o Node.\n"
	"show con - Imprime as conexoes atuais com outros equipamentos.\n"
	"add route w x y z - Cria nova rota estatica com o destino w, a mascara x, o gateway y e a interface z.\n"
	"del route w - Remove a rota estatica para o destino w.\n"
	"show table - Mostra a tabela de roteamento.\n"
	"clear table - Limpa a tabela de roteamento.\n"
	"set mac n - Escreve um novo endereco MAC n para o dispositivo.\n"
	"set ip n - Escreve um novo endereco IP n para o dispositivo.\n"
	"set mask n - Escreve uma nova mascara de rede n para o dispositivo.\n"
	"get mac - Imprime o endereco MAC para o dispositivo.\n"
	"get ip - Imprime o endereco IP para o dispositivo.\n"
	"get mask - Imprime a mascara de rede para o dispositivo.\n"
	"exit - Sai do console e volta para o simulador.\n"
	"\n\n";
}

void Router::addto_routing_table(string composition)
{
	int ninterf,count = 0;
	Routing* route = new Routing();
	string str,destination,netmask,gateway,interf_str;
    istringstream f(composition);
    while(getline(f,str,' ')){
		if(count == 0) destination = str;
		else if(count == 1) netmask = str;
		else if(count == 2) gateway = str;
		else if(count == 3) interf_str = str;
		count++;
	}
	route->netmask = netmask;
	route->gateway = gateway;
	istringstream buffer(interf_str); buffer >> ninterf;
	for(mapit = interfaces.begin(); mapit != interfaces.end(); mapit++)
		if((*mapit).second->identifier == ninterf) route->interf = (*mapit).second;
	if(route->interf != NULL) this->routing_table[destination] = route;
}

void Router::remfrom_routing_table(string destination)
{
	rtit = routing_table.find(destination);
	if(rtit != routing_table.end()) routing_table.erase(rtit);
}

void Router::show_routing_table()
{
	size_t interf;
	string destination,netmask,gateway;
	cout << "Tabela de roteamento do " << name << ":\n";
	cout << "Destino | Mascara de Rede | Default Gateway | Interface" << endl;
	for(rtit = routing_table.begin(); rtit != routing_table.end(); rtit++){
		destination = rtit->first;
		netmask = rtit->second->netmask;
		gateway = rtit->second->gateway;
		interf = rtit->second->interf->identifier;
		cout << destination << " | " << netmask << " | " << gateway << " | " << interf << endl;
	}
}