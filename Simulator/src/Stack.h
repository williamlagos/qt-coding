#include<cstdint>
#include<string>
#include<ostream>
using namespace std;

#define VALUE long
#define TYPE short
#define SIZE int
#define ARP_REQUEST 1
#define ARP_REPLY 2
#define ARPP 0x0806
#define IPV4 0x0800
#define ETH 1
#define ICMPV4 1
#define INFO_REQUEST 30
#define ECHO_REQUEST 8
#define ECHO_REPLY 0

typedef struct{
	string destination; //Destination MAC address.
	string source; //Source MAC address.
	TYPE type;  //The packet type.
	string data;
} Ethernet;

typedef struct{
	SIZE mac_size;
	TYPE mac_type;
	SIZE protocol_size;
	TYPE protocol_type;
	VALUE arp_operation;
	//Address
	string sender_mac;
	string sender_ipaddress;
	string target_mac;
	string target_ipaddress;
} ARP;

typedef struct{
	SIZE 	header_len;	//The header length.
	VALUE 	ip_version;	//The IP version.
	TYPE 	type_service;	//Type of Service.
	SIZE 	packet_length;		//IP packet length (both data and header).
	VALUE 	identification;			//Identification.
	VALUE 	offset;			//Fragment offset.
	VALUE 	timetolive;			//Time To Live.
	TYPE 	protocol;		//The type of the upper-level protocol.
	VALUE 	checksum;			//IP header checksum.
	string 	ip_source;			//IP source address (in network format).
	string 	ip_destination;			//IP destination address (in network format). 
} IPv4;

typedef struct{
	TYPE type;
	VALUE code;
	VALUE checksum;
	string data;
} ICMPv4;

typedef struct{
	Ethernet* eth;
	ARP* arp;
	IPv4* ipv4;
	ICMPv4* icmpv4;
} PACKET;

ostream& operator<<(ostream& os, Ethernet& arp);
ostream& operator<<(ostream& os, ARP& arp);
ostream& operator<<(ostream& os, IPv4& arp);
ostream& operator<<(ostream& os, ICMPv4& arp);
ostream& operator<<(ostream& os, PACKET& packet);