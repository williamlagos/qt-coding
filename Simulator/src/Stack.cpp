#include"Stack.h"

ostream& operator<<(ostream& os,Ethernet& eth)
{
	os << "Cabecalho Ethernet" << endl
	<< "Endereco MAC Destino: " << eth.destination << endl
	<< "Endereco MAC Origem: " << eth.source << endl
	<< "Tipo de Pacote Ethernet: " << eth.type << endl
	<< "Dados do Pacote Ethernet: " << eth.data << endl;
	return os;
}

ostream& operator<<(ostream& os, ARP& arp)
{
	os << "Cabecalho ARP" << endl
	<< "Tamanho do Endereco MAC: " << arp.mac_size << endl
	<< "Tipo do Endereco MAC: " << arp.mac_type << endl
	<< "Tamanho do Protocolo: " << arp.protocol_size << endl
	<< "Tipo de Protocol: " << arp.protocol_type << endl
	<< "Operacao ARP: " << arp.arp_operation << endl
	//Enderecos
	<< "Endereco MAC Origem: " << arp.sender_mac << endl
	<< "Endereco MAC Destino: " << arp.target_mac << endl
	<< "Endereco IP Origem: " << arp.sender_ipaddress << endl
	<< "Endereco IP Destino: " << arp.target_ipaddress << endl;
	return os;
}

ostream& operator<<(ostream& os, IPv4& ipv4)
{
	os << "Cabecalho IPv4" << endl
	<< "Tamanho do Cabecalho: " << ipv4.header_len << endl
	<< "Versao do IP: " << ipv4.ip_version << endl
	<< "Tipo de Servico: " << ipv4.type_service << endl
	<< "Tamanho do Pacote: " << ipv4.packet_length << endl
	<< "ID do Cabecalho: " << ipv4.identification << endl
	<< "Offset: " << ipv4.offset << endl
	<< "TTL: " << ipv4.timetolive << endl
	<< "Protocolo: " << ipv4.protocol << endl
	<< "Checksum: " << ipv4.checksum << endl
	//Enderecos
	<< "Endereco IP Origem: " << ipv4.ip_source << endl
	<< "Endereco IP Destino: " << ipv4.ip_destination << endl;
	return os;
}

ostream& operator<<(ostream& os, ICMPv4& icmpv4)
{
	os << "Cabecalho ICMPv4" << endl
	<< "Tipo de Mensagem: " << icmpv4.type << endl
	<< "Codigo da Mensagem: " << icmpv4.code << endl
	<< "Checksum: " << icmpv4.checksum << endl
	<< "Dados do Cabecalho ICMPv4: " << icmpv4.data << endl;
	return os;
}

ostream& operator<<(ostream& os,PACKET& packet)
{
	os << "Pacote interceptado:" << endl << (*packet.eth);
	if(packet.arp != NULL) os << endl << (*packet.arp);
	else os << endl << (*packet.ipv4) << endl << (*packet.icmpv4);
	return os;
}