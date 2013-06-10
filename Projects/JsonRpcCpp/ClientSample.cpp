#include "Sample.h"

#include <cstdio>
#include <cstdlib>

/**
 * \brief Entry point of the program.
 * \param argc number of argument
 * \param argv array of arguments
 * \return EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char** argv)
{
  Json::Rpc::TcpClient *tcpClient = new Json::Rpc::TcpClient(std::string("127.0.0.1"), 8086);
  Json::Value query;
  Json::FastWriter writer;
  std::string queryStr;
  std::string responseStr;
  
  /* avoid compilation warnings */
  argc = argc;
  argv = argv;

  if(!networking::init())
  {
    std::cerr << "Networking initialization failed" << std::endl;
    exit(EXIT_FAILURE);
  }

  if(!tcpClient->Connect())
  {
    std::cerr << "Cannot connect to remote peer!" << std::endl;
    exit(EXIT_FAILURE);
  }

  /* build JSON-RPC query */
  query["jsonrpc"] = "2.0";
  query["id"] = 1;
  query["method"] = "print";

  queryStr = writer.write(query);
  std::cout << "Query is: " << queryStr << std::endl;

  if(tcpClient->Send(queryStr) == -1)
  {
    std::cerr << "Error while sending data!" << std::endl;
    exit(EXIT_FAILURE);
  }

  /* wait the response */
  if(tcpClient->Recv(responseStr) != -1)
  {
    std::cout << "Received: " << responseStr << std::endl;
  }
  else
  {
    std::cerr << "Error while receiving data!" << std::endl;
  }

  tcpClient->Close();
  delete tcpClient;
  networking::cleanup();

  return EXIT_SUCCESS;
}