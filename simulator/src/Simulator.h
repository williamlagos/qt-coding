#include"Common.h"

class Simulator: public QObject{
	Q_OBJECT
private:
	MAP emptymap;
	LST emptylst;
	stringstream ss;
public:
	Simulator();
	~Simulator();
	void parse_command(string);
	void read_topology(string name);
	void help();
	int simulate();
	void exit_simulator();
	template<typename T> void execute_console(T*,string,int);
	template<typename F,typename S> void show(string,vector<S*>&);
	template<typename F,typename S> void select(string,string,vector<S*>&);
	template<typename F,typename S> void connect_interface(F*,S*);
public slots:
	void create_node	(MAP* map = NULL);
	void create_router	(MAP* map = NULL);
	void create_switch	(LST* lst = NULL);
	void create_hub		(LST* lst = NULL);
signals:
	void send_namefile(string);
};