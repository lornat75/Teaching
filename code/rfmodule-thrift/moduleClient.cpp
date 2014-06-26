#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/RpcClient.h>

#include "Memory.h"

using namespace std;
using namespace yarp::os;

int main(int argc, char * argv[])
{
    Network yarp;

    RpcClient port;

    port.open("/client");

    Network::connect("/client", "/myModule");

    Memory client;

    client.yarp().attachAsClient(port);

    //use functions defined in Memory.h
    
    client.push("hello", "world");
    std::string answer=client.get_answer("hello");

    cout<<"Main returning..."<<endl;
    return 0;
}




