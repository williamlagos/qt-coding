#include "codes.h"

Codes::Codes()
{
    root = code.begin();
    target = code.insert(root,GRAY);
}

Codes::~Codes()
{

}

string Codes::black()
{
    if(code.number_of_children(target) == 4) return "Quadros preto/branco demais num quadrante";
    code.append_child(target,BLACK);
    return printTree();
}

string Codes::white()
{
    if(code.number_of_children(target) >= 4) return "Quadros preto/branco demais num quadrante";
    code.append_child(target,WHITE);
    return printTree();
}

string Codes::gray()
{
    tree<int>::iterator node,source;
    source = code.insert(code.end()--,GRAY);
    node = code.append_child(source,GRAY);
    code.append_child(source,GRAY);
    code.append_child(source,GRAY);
    code.move_before(target,source);
    target = node;
    return printTree();
}

string Codes::parseCode(std::string text)
{
    string::iterator it;
    string message = "";
    int index = 0;
    for(it = text.begin(); it < text.end(); it++ ,index++){
           switch(*it){
           case 'b':
               message = white();
               break;
           case 'p':
               message = black();
               break;
           case 'c':
               message = gray();
               break;
           default:
               message = "Token desconhecido!";
               break;
           }
    }
    return message;
}

void Codes::clearTree()
{
    code.clear();
    printTree();
    root = code.begin();
    target = code.insert(root,GRAY);
}

string Codes::printTree()
{
    string str = "";
    vector<int>::iterator it;
    vector<int> v = sourceTree();
    for(it = v.begin(); it != v.end(); it++){
        ostringstream oss;
        oss << (*it);
        str.append(oss.str());
    }
    return str;
}

vector<int> Codes::sourceTree()
{
    vector<int> v;
    tree<int>::pre_order_iterator it;
    for(it = code.begin(); it != code.end(); it++)
        v.push_back(*it);
    return v;
}

int Codes::blacks()
{
    tree<int>::iterator it;
    vector<int> v;
    int count = 0;
    for(it = code.begin(); it != code.end(); it++){
        if((*it) == BLACK) count++;
    }
    return count;
}
