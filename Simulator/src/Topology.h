#include"Common.h"

class Reader: public QThread{
	Q_OBJECT
public:
	Reader(){}
	~Reader(){}
	void run();
public slots:
	void read_filename(string);
signals:
	void send_nodes(MAP*);
	void send_routers(MAP*);
	void send_switches(LST*);
	void send_hubs(LST*);
};