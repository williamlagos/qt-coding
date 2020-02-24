#include"Topology.h"
#include"Exceptions.h"

void Reader::run(){}

void Reader::read_filename(string filename)
{
	QFile json(filename.c_str());
	QJsonDocument doc;
	cout << "Lendo o arquivo de topologia " << filename << "..." << endl;

	try{ 
		if(!(json.open(QIODevice::ReadOnly | QIODevice::Text))) throw IOException();
		doc = QJsonDocument::fromJson(json.readAll());
		if(doc.isEmpty()) throw ParseException();
	}catch(exception& e){ cout << e.what() << endl; return; }

	QVariantMap vmap = doc.object().toVariantMap();
	MAP nodes = getMAP(vmap["nodes"]);
	MAP routers = getMAP(vmap["routers"]);
	LST switches = getLST(vmap["switches"]);
	LST hubs = getLST(vmap["hubs"]);

	emit this->send_nodes(&nodes);
	emit this->send_routers(&routers);
	emit this->send_switches(&switches);
	emit this->send_hubs(&hubs);
}