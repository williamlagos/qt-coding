#include <iostream>
#include <jsonrpc.h>
using namespace Json;
using namespace Json::Rpc;
using std::cout;
using std::endl;

class SimpleClass{
public:
  SimpleClass(){};
  void Print();
};

class MyClass{
public:
  bool Func(const Json::Value& root, Json::Value& response);
  Json::Value GetFuncDescription();
};