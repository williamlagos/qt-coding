PROJECT(JsonRpcCpp)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#SET(CMAKE_CXX_FLAGS "-std=c++98 -Wall -W -pedantic -Wredundant-decls -Wshadow -Werror -O2")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_DIR}../JsonCppLib/include)
LINK_DIRECTORIES(${CMAKE_CURRENT_DIR}../JsonCppLib/build/vs71/debug/lib_json)
ADD_LIBRARY(jsonrpc jsonrpc_handler.cpp jsonrpc_server.cpp jsonrpc_client.cpp jsonrpc_udpserver.cpp jsonrpc_tcpserver.cpp jsonrpc_udpclient.cpp jsonrpc_tcpclient.cpp netstring.cpp networking.cpp)

TARGET_LINK_LIBRARIES(jsonrpc json_vc71_libmtd)
