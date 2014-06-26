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

  
    cout<<"Main returning..."<<endl;
    return 0;
}




