#include"Equipment.h"
#include"Exceptions.h"

Node::Node(string name, string mac_address):Equipment(name)
{
	this->mac_address = mac_address;
}

bool Node::parse_command(string cmd)
{
	try{
		if(contains(cmd,"set")){ 
			if(contains(cmd,"name",8)) this->name = substring(cmd,9);
			else if(contains(cmd,"mac",7)) this->mac_address = substring(cmd,8);
			else if(contains(cmd,"ip",6)) this->ip_address = substring(cmd,7);
			else if(contains(cmd,"gw",6)) this->gw_address = substring(cmd,7);
			else if(contains(cmd,"mask",8)) this->address_mask = substring(cmd,9);
			else throw CommandException();
		}else if(contains(cmd,"get")){ 
			if(contains(cmd,"name")) cout << this->name << endl;
			else if(contains(cmd,"mac")) cout << this->mac_address << endl;
			else if(contains(cmd,"ip")) cout << this->ip_address << endl;
			else if(contains(cmd,"gw")) cout << this->gw_address << endl;
			else if(contains(cmd,"mask")) cout << this->address_mask << endl;
			else throw CommandException();
		}
		else if(contains(cmd,"ping")) this->ping(substring(cmd,5));
		else if(contains(cmd,"traceroute")) this->traceroute(substring(cmd,11));
		else if(contains(cmd,"show con")) this->show_connections();
		else if(contains(cmd,"show arp")) this->show_arp_cache();
		else if(contains(cmd,"clear arp")) arp_cache.clear();
		else if(contains(cmd,"help")) this->help();
		else if(contains(cmd,"exit")) return false;
		else throw CommandException();
	}catch(exception &e){ cout << e.what() << endl; }
	return true;
}

void Node::help()
{
	cout << "Comandos para execucao no console do Node:\n\n"
	"set name n - Escreve um novo nome n para o Node.\n"
	"get name - Imprime o nome atual para o Node.\n"
	"show con - Imprime as conexoes atuais com outros equipamentos.\n"
	"set mac n - Escreve um novo endereco MAC n para o dispositivo.\n"
	"set ip n - Escreve um novo endereco IP n para o dispositivo.\n"
	"set gw n - Escreve um novo default gateway n para o dispositivo.\n"
	"set mask n - Escreve uma nova mascara de rede n para o dispositivo.\n"
	"get mac - Imprime o endereco MAC para o dispositivo.\n"
	"get ip - Imprime o endereco IP para o dispositivo.\n"
	"get gw - Imprime o default gateway para o dispositivo.\n"
	"get mask - Imprime a mascara de rede para o dispositivo.\n"
	"ping n - Executa o comando ping para o endereco n.\n"
	"traceroute n - Executa o comando traceroute para o endereco n.\n"
	"show arp - Mostra a ARP cache do Node.\n"
	"clear arp - Limpa a ARP cache do Node.\n"
	"exit - Sai do console e volta para o simulador.\n"
	"\n\n";
}

void Node::arp_request(PACKET* arp_packet, string target_address)
{
	Ethernet* eth = new Ethernet();
	eth->destination = "FF:FF:FF:FF:FF:FF";
	eth->source = this->mac_address;
	eth->type = ARPP;
	eth->data = "";
	arp_packet->eth = eth;

	ARP* arp = new ARP();
	arp->mac_type = ETH;
	arp->mac_size = 6;
	arp->protocol_type = IPV4;
	arp->protocol_size = 4;
	arp->arp_operation = ARP_REQUEST;
	arp->sender_mac = this->mac_address;
	arp->sender_ipaddress = this->ip_address;
	arp->target_mac = "00:00:00:00:00:00";
	arp->target_ipaddress = target_address;
	arp_packet->arp = arp;

	arp_packet->ipv4 = NULL;
	arp_packet->icmpv4 = NULL;
	emit packet_sended((void*)arp_packet);
}

void Node::arp_reply(PACKET* arp_packet)
{
	Ethernet* eth = new Ethernet();
	eth->destination = arp_packet->eth->source;
	eth->source = this->mac_address;
	eth->type = ARPP;
	eth->data = "";
	arp_packet->eth = eth;

	ARP* arp = new ARP();
	arp->mac_type = ETH;
	arp->mac_size = 6;
	arp->protocol_type = IPV4;
	arp->protocol_size = 4;
	arp->arp_operation = ARP_REPLY;
	arp->sender_mac = arp_packet->arp->sender_mac;
	arp->sender_ipaddress = arp_packet->arp->sender_ipaddress;
	arp->target_mac = this->mac_address;
	arp->target_ipaddress = this->ip_address;
	arp_packet->arp = arp;

	arp_packet->ipv4 = NULL;
	arp_packet->icmpv4 = NULL;
	emit packet_sended((void*)arp_packet);
}

void Node::cache_arp(PACKET* arp_packet)
{
	string ipa = arp_packet->arp->target_ipaddress;
	string mac = arp_packet->arp->target_mac;
	arp_cache[ipa] = mac;
}

void Node::show_arp_cache()
{
	cout << "Tabela ARP: " << endl;
	for(arpit = arp_cache.begin(); arpit != arp_cache.end(); arpit++)
		cout << "Endereco IP: " << arpit->first << " - Endereco MAC: " << arpit->second << endl;
}

void Node::icmp_echo_request(PACKET* icmp_packet,string address)
{
	Ethernet* eth = new Ethernet();
	eth->destination = arp_cache[address];
	eth->source = this->mac_address;
	eth->type = IPV4;
	eth->data = "";
	icmp_packet->eth = eth;

	IPv4* ipv4 = new IPv4();
	ipv4->header_len = sizeof(IPv4);
	ipv4->ip_version = 4;
	ipv4->type_service = 0;
	ipv4->packet_length = sizeof(PACKET);
	ipv4->identification = 0;
	ipv4->offset = 0; //Sem fragmentacao
	ipv4->timetolive = 64;
	ipv4->protocol = ICMPV4;
	ipv4->checksum = 0; //Sem checksum
	ipv4->ip_source = this->ip_address;
	ipv4->ip_destination = address;
	icmp_packet->ipv4 = ipv4;

	ICMPv4* icmpv4 = new ICMPv4();
	icmpv4->type = ECHO_REQUEST;
	icmpv4->code = 0;
	icmpv4->checksum = 0; //Sem checksum
	icmpv4->data = "";
	icmp_packet->icmpv4 = icmpv4;

	icmp_packet->arp = NULL;
	emit packet_sended((void*)icmp_packet);
}

void Node::icmp_echo_reply(PACKET* icmp_packet)
{
	string destination = icmp_packet->ipv4->ip_destination;

	Ethernet* eth = new Ethernet();
	eth->destination = icmp_packet->eth->source;
	eth->source = icmp_packet->eth->destination;
	eth->type = IPV4;
	eth->data = "";
	icmp_packet->eth = eth;

	IPv4* ipv4 = new IPv4();
	ipv4->header_len = sizeof(IPv4);
	ipv4->ip_version = 4;
	ipv4->type_service = 0;
	ipv4->packet_length = sizeof(PACKET);
	ipv4->identification = 0;
	ipv4->offset = 0; //Sem fragmentacao
	ipv4->timetolive = 64;
	ipv4->protocol = ICMPV4;
	ipv4->checksum = 0; //Sem checksum
	ipv4->ip_source = this->ip_address;
	ipv4->ip_destination = icmp_packet->ipv4->ip_source;
	icmp_packet->ipv4 = ipv4;

	ICMPv4* icmpv4 = new ICMPv4();
	icmpv4->type = ECHO_REPLY;
	icmpv4->code = 0;
	icmpv4->checksum = 0; //Sem checksum
	icmpv4->data = "";
	icmp_packet->icmpv4 = icmpv4;

	icmp_packet->arp = NULL;
	if(contains(this->ip_address,destination)){ emit packet_sended((void*)icmp_packet); return; }

	Interface* interf = interfaces[destination];
	CONNECTOR conn = interf->con;
	if(contains(interf->type,"Hub")) ((Hub*)conn)->packet_receive((void*)icmp_packet);
	else if(contains(interf->type,"Node")) ((Node*)conn)->packet_receive((void*)icmp_packet);
	else if(contains(interf->type,"Router")) ((Router*)conn)->packet_receive((void*)icmp_packet);
	else if(contains(interf->type,"Switch")) ((Switch*)conn)->packet_receive((void*)icmp_packet);
}

void Node::stream_echo_reply(PACKET* icmp_packet)
{
	cout << "Pacote recebido (ECHO REPLY): " << icmp_packet->ipv4->ip_source
	<< " - TTL: " << icmp_packet->ipv4->timetolive 
	<< " - Tamanho: " << icmp_packet->ipv4->packet_length << endl;
}

void Node::icmp_info_request(PACKET* packet, string address)
{
	string ip_destination = "";
	if(packet->ipv4 != NULL) ip_destination = packet->ipv4->ip_destination;
	time_t timestamp = time(0);
	Ethernet* eth = new Ethernet();
	eth->destination = arp_cache[address];
	eth->source = this->mac_address;
	eth->type = IPV4;
	eth->data = "";
	icmp_packet->eth = eth;

	IPv4* ipv4 = new IPv4();
	ipv4->header_len = sizeof(IPv4);
	ipv4->ip_version = 4;
	ipv4->type_service = 0;
	ipv4->packet_length = sizeof(PACKET);
	ipv4->identification = 0;
	ipv4->offset = 0; //Sem fragmentacao
	if(icmp_packet->ipv4->timetolive != NULL) 
		ipv4->timetolive = icmp_packet->ipv4->timetolive-1;
	else ipv4->timetolive = 64;
	ipv4->protocol = ICMPV4;
	ipv4->checksum = 0; //Sem checksum
	ipv4->ip_source = this->ip_address;
	ipv4->ip_destination = address;
	icmp_packet->ipv4 = ipv4;

	ICMPv4* icmpv4 = new ICMPv4();
	icmpv4->type = INFO_REQUEST;
	icmpv4->code = 0;
	icmpv4->checksum = 0; //Sem checksum
	icmpv4->data = "";
	icmp_packet->icmpv4 = icmpv4;

	icmp_packet->arp = NULL;
	cout << "Nodo passado (Tempo: " << time(0)-timestamp << ") - " << this << endl;
	if(!contains(ip_destination,this->ip_address)) emit packet_sended((void*)icmp_packet);
}

void Node::verify_arp_cache(string address)
{
	time_t timestamp = time(0);
	//Endereco nao esta na ARP Cache. Comecando o processo do ARP
	if(arp_cache.size() < 1 || arp_cache.find(address) == arp_cache.end()) arp_request(this->arp_packet,address);
	//Aguardando 15 segundos para o retorno de resposta, caso contrario, Timeout
	while(arp_cache.find(address) == arp_cache.end()){ 
		try { if(time(0)-timestamp > 15) throw TimeoutException(); }
		catch(exception& e){ cout << e.what() << endl; break; }
	}
}

void Node::ping(string address)
{
	string icmp_ping_buffer = "";
	this->verify_arp_cache(address);
	icmp_echo_request(this->icmp_packet,address);
}

void Node::traceroute(string address)
{	
	this->verify_arp_cache(address);
	icmp_info_request(this->icmp_packet,address);
}

void Node::packet_receive(void* packet)
{
	time_t timestamp = time(0);
	stringstream ss;
	PACKET* pkt = (PACKET*) packet;
	ss << "Trafego de pacotes no " << name << ":\n" << (*pkt) << endl; this->write(ss.str(),time(0)-timestamp);
	ARP* arp = pkt->arp; ICMPv4* icmp = pkt->icmpv4;
	//Recebimento de ARP Request e envio de ARP Reply
	if(arp != NULL){
		if(contains(arp->target_ipaddress,this->ip_address) && arp->arp_operation == ARP_REQUEST) this->arp_reply((PACKET*)packet);
		else if(contains(arp->sender_ipaddress,this->ip_address) && arp->arp_operation == ARP_REPLY) this->cache_arp((PACKET*)packet);
	}else if(icmp != NULL){
		if(contains(pkt->ipv4->ip_destination,this->ip_address)){
			if(icmp->type == ECHO_REQUEST) this->icmp_echo_reply((PACKET*)packet);
			else if(icmp->type == ECHO_REPLY) this->stream_echo_reply((PACKET*)packet);
			else if(icmp->type == INFO_REQUEST) this->icmp_info_request((PACKET*)packet,pkt->ipv4->ip_destination);
		}
	}
}

void Node::add_interface(string address,Interface* interf){ this->interfaces[address] = interf; }