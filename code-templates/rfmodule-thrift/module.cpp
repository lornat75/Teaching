#include <iostream>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Semaphore.h>

#include <map>

#include "Memory.h"

using namespace std;
using namespace yarp::os;

typedef std::map<std::string, std::string> DataBase;
typedef DataBase::const_iterator DataBaseConstIterator;
typedef DataBase::iterator DataBaseIterator;

class MyModule: public Memory, public RFModule 
{
    RpcServer handlerPort; //a port to handle messages
    // Semaphore wait;

    DataBase db;

    int count;
public:

    double getPeriod()
    {
        return 1; //module periodicity (seconds)
    }

    /*
    * This is our main function. Will be called periodically every getPeriod() seconds.
    */
    bool updateModule()
    {
        // wait.wait();
        count++;
        //printf("[%d] updateModule\n", count);
        cout<<"["<<count<<"]"<< " updateModule... "<<endl;

        return true;
    }

        /* 
    * Configure function. Receive a previously initialized
    * resource finder object. Use it to configure your module.
    * Open port and attach it to message handler.
    */
    bool configure(yarp::os::ResourceFinder &rf)
    {
        count=0;
        return true;
    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module, for unblocking waiting operations"<<endl;
        //wait.post();
        return true;
    }

    /*
    * Close function, to perform cleanup.
    */
    bool close()
    {
        cout<<"Calling close function\n";
        handlerPort.close();
        return true;
    }

   
};

int main(int argc, char * argv[])
{
    Network yarp;

    MyModule module;
    ResourceFinder rf;
    rf.configure(argc, argv);
    // rf.setVerbose(true);

    cout<<"Configure module..."<<endl;
    module.configure(rf);
    cout<<"Start module..."<<endl;
    module.runModule();

    cout<<"Main returning..."<<endl;
    return 0;
}




