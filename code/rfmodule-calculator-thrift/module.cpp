#include <iostream>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>

#include <Calculator.h>

using namespace std;
using namespace yarp::os;


class MyModule: public RFModule, public Calculator 
{
    RpcServer handlerPort; //a port to handle messages
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
        count++;
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
        handlerPort.open("/myModule");
        
        yarp().attachAsServer(handlerPort);
        return true;
    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module, for unblocking waiting operations"<<endl;
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

  virtual int32_t sum(const int32_t a, const int32_t b) {
    return a + b;
  }

  virtual int32_t sub(const int32_t a, const int32_t b) {
    return a - b;
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




