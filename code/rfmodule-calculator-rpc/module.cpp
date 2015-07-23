#include <iostream>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>

using namespace std;
using namespace yarp::os;

class MyModule : public RFModule
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
        //printf("[%d] updateModule\n", count);
        cout<<"["<<count<<"]"<< " updateModule... "<<endl;

        return true;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int sum(int a, int b) {
        return a + b;
    }


    /*
    * Message handler. Just echo all received messages.
    */
    bool respond(const Bottle& command, Bottle& reply) 
    {
        cout<<"Got "<<command.toString().c_str()<<endl;

        if(command.size() < 3) {
            reply.addString("Command error! example: 'sum 3 4'");
            return true;
        }
        int a = command.get(1).asInt();
        int b = command.get(2).asInt();

        if( command.get(0).asString() == "sum") {
           int c = sum(a, b);
            reply.addInt(c);
            return true;
        }

        if( command.get(0).asString() == "sub") {
            int c = sub(a, b);
            reply.addInt(c);
            return true;
        }

        reply.addString("Unknown command");
        reply.addString(command.get(0).asString().c_str());
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
        attach(handlerPort);
        return true;
    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module, for port cleanup"<<endl;
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


