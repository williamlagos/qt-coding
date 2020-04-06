#include"Topology.h"
#include"Simulator.h"

int main(int argc,char *argv[])
{
	Reader *r = new Reader(); r->start();
	Simulator *s = new Simulator();

	QObject::connect(s,&Simulator::send_namefile,r,&Reader::read_filename);
	QObject::connect(r,&Reader::send_hubs,s,&Simulator::create_hub);
	QObject::connect(r,&Reader::send_nodes,s,&Simulator::create_node);
	QObject::connect(r,&Reader::send_routers,s,&Simulator::create_router);
	QObject::connect(r,&Reader::send_switches,s,&Simulator::create_switch);

	return s->simulate();
}