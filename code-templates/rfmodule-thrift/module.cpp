#include <iostream>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Semaphore.h>

#include "Memory.h"

using namespace std;
using namespace yarp::os;

class MyModule: public Memory, public RFModule 
{
  
  
};

int main(int argc, char * argv[])
{
    Network yarp;

   
    return 0;
}




