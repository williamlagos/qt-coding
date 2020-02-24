#include"Common.h"
#include"Stack.h"

typedef struct{
	ID identifier;
	CONNECTOR con;
	string type;
} Interface;

typedef struct{
	string netmask;
	string gateway;
	Interface* interf;
} Routing;

class Equipment: public QThread{
	Q_OBJECT
protected:
	string name;
	string mac_address;
	string ip_address;
	bool activated;
	map<string,Interface*> interfaces;
	map<string,Interface*>::iterator mapit;
	PACKET* arp_packet;
	PACKET* icmp_packet;
	ofstream log;
public:
	Equipment(string name="Equipment");
	~Equipment();
	void show_connections();
	bool parse_command(string);
	void start_writer();
	void write(string,time_t);
	void run();
	void help();
	void add_interface(string,Interface*);
	string get_ip_address(){ return this->ip_address; }
	string get_mac_address(){ return this->mac_address; }
	map<string,Interface*> get_interfaces(){ return this->interfaces; }
	friend ostream& operator<<(ostream& os,const Equipment& equip){}
public slots:
	void packet_receive(void*){}
signals:
	void packet_sended(void*);
};

class Hub: public Equipment{
	Q_OBJECT
public:
	Hub(string);
	friend ostream& operator<<(ostream& os,const Hub& hub){
		os << endl << "Hub de nome " << hub.name << " | Status: "; 
		if(hub.activated) os << "Ativado" << endl;
		else os << "Desativado" << endl;
		return os;
	}
public slots:
	void packet_receive(void*);
signals:
	void packet_sended(void*);
};

class Switch: public Equipment{
	Q_OBJECT
private:
	map<string,Interface*> switch_table;
	map<string,Interface*>::iterator mapit;
public:
	Switch(string);
	void help();
	void addto_mac_table(string,Interface*);
	void show_mac_table();
	bool parse_command(string);
	friend ostream& operator<<(ostream& os,const Switch &swtch){
		os << endl << "Switch de nome " << swtch.name << " | Status: "; 
		if(swtch.activated) os << "Ativado" << endl;
		else os << "Desativado" << endl;
		return os;
	}
public slots:
	void packet_receive(void*);
signals:
	void packet_sended(void*);
};

class Node: public Equipment{
	Q_OBJECT
protected:
	string gw_address;
	string address_mask;
	map<string,string> arp_cache;
	map<string,string>::iterator arpit;
public:
	Node(string,string);
	void help();
	bool parse_command(string);
	void ping(string);
	void traceroute(string);
	void arp_request(PACKET*,string);
	void arp_reply(PACKET*);
	void cache_arp(PACKET*);
	void show_arp_cache();
	void verify_arp_cache(string);
	void icmp_echo_request(PACKET*,string);
	void icmp_echo_reply(PACKET*);
	void icmp_info_request(PACKET*,string);
	void stream_echo_reply(PACKET*);
	void add_interface(string,Interface*);
	friend ostream& operator<<(ostream& os,const Node &node){
		os << endl << "Node de nome " << node.name << " | Status: "; 
		if(node.activated) os << "Ativado" << endl;
		else os << "Desativado" << endl;
		os << "Informacoes de Enderecamento: " << endl
		<< "Endereco MAC: " << node.mac_address << endl
		<< "Endereco IP: " << node.ip_address << endl
		<< "Default Gateway: " << node.gw_address << endl
		<< "Mascara de Endereco: " << node.address_mask << endl;
		return os;
	}
public slots:
	void packet_receive(void*);
signals:
	void packet_sended(void*);
};

class Router: public Node{
	Q_OBJECT
private:
	map<string,Routing*> routing_table;
	map<string,Routing*>::iterator rtit;
public:
	Router(string,string,int);
	void addto_routing_table(string);
	void remfrom_routing_table(string);
	void show_routing_table();
	bool parse_command(string);
	void help();
	friend ostream& operator<<(ostream& os,const Router &router){
		os << endl << "Router de nome " << router.name << " | Status: "; 
		if(router.activated) os << "Ativado" << endl;
		else os << "Desativado" << endl;
		os << "Informacoes de Enderecamento: " << endl
		<< "Endereco MAC: " << router.mac_address << endl
		<< "Endereco IP: " << router.ip_address << endl
		<< "Mascara de Endereco: " << router.address_mask << endl;
		return os;
	}
public slots:
	void packet_receive(void*);
signals:
	void packet_sended(void*);
};
