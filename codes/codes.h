#ifndef CODES_H
#define CODES_H
#include <string>
#include <sstream>
#include <iostream>
#include "tree.h"

#define BLACK 0
#define WHITE 1
#define GRAY 2

using namespace std;

class Codes
{
private:
    tree<int> code;
    tree<int>::iterator root,target;
public:
    Codes();
    ~Codes();
    int blacks();
    vector<int> sourceTree();
    string      printTree();
    string      parseCode(string);
    string      black();
    string      white();
    string      gray();
    void        clearTree();
};

#endif // CODES_H
