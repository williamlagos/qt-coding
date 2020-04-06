#include<QtCore>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<ctime>
using namespace std;

#define MAP map<QString,QVariant>
#define MAP_ITERATOR map<QString,QVariant>::iterator
#define LST vector<QVariant>
#define LST_ITERATOR vector<QVariant>::iterator
#define STR string
#define CONNECTOR void*
#define ID size_t

MAP getMAP(QVariant value);
LST getLST(QVariant value);
STR getSTR(QVariant value);

bool contains(string name,string str);
bool contains(string name,string str,int delim);
string substring(string name,int delim);