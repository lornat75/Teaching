#include <iostream>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Thread.h>
#include <yarp/os/Time.h>
#include <yarp/os/Mutex.h> 

using namespace std;
using namespace yarp::os;


Mutex key;

class WorkerThread : public yarp::os::Thread {
public:
    WorkerThread(unsigned int id) {
      myID = id;
    }

    bool threadInit() {
        cout<<"initializing worker "<<myID<<"."<<endl;
        return true;
    }

    void run() {
        while(!isStopping()) {
            
            key.lock();
            cout<<"Worker "<<myID<<" says Hi!"<<endl;
            key.unlock();

            Time::delay(0.2);
        }
    }
private:
    unsigned int myID;
};



class MyModule:public RFModule
{
    int count;
   WorkerThread* worker1;
   WorkerThread* worker2;

public:

    double getPeriod() {
        return 1; //module periodicity (seconds)
    }

    /*
    * This is our main function. Will be called periodically every getPeriod() seconds.
    */
    bool updateModule()
    {
        count++;
        key.lock();
        cout<<"["<<count<<"]"<< " updateModule... "<<endl;
        key.unlock();
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
        worker1 = new WorkerThread(1);
        worker2 = new WorkerThread(2);
        cout<<"Staring worker thread..."<<endl;
        worker1->start();
        worker2->start();
        return true;
    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module to stop the worker thread..."<<endl;
        worker1->stop();
        worker2->stop();
        return true;
    }

    /*
    * Close function, to perform cleanup.
    */
    bool close()
    {
        cout<<"Calling close function\n";
        delete worker1;
        delete worker2;
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


