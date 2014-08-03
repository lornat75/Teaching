// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
//
// A tutorial on how to use the Gaze Interface.
//
// Author: Ugo Pattacini - <ugo.pattacini@iit.it>

#include <string>

#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/RateThread.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Time.h>
#include <yarp/sig/Vector.h>

#include <yarp/dev/Drivers.h>
#include <yarp/dev/GazeControl.h>
#include <yarp/dev/PolyDriver.h>

YARP_DECLARE_DEVICES(icubmod)

using namespace std;
using namespace yarp::os;
using namespace yarp::dev;
using namespace yarp::sig;


class CtrlThread: public RateThread
{
protected:
    ResourceFinder &rf;

    PolyDriver      clientGaze;
    IGazeControl   *igaze;

    int state;
    int startup_context_id;

    BufferedPort<Bottle> port;

public:
    CtrlThread(ResourceFinder &_rf) : RateThread(20), rf(_rf) { }

    bool threadInit()
    {
        string name=rf.find("name").asString().c_str();
        double period=rf.find("period").asDouble();
        setRate(int(1000.0*period));

        // open a client interface to connect to the gaze server
        // we suppose that:
        // 1 - the iCub simulator (icubSim) is running
        // 2 - the gaze server iKinGazeCtrl is running and
        //     launched with the following options:
        //     --robot icubSim --context cameraCalibration/conf --config icubSimEyes.ini

        // FILL IN THE CODE

        port.open(("/"+name+"/target:i").c_str());

        return true;
    }

    void run()
    {
        Bottle *pTarget=port.read(false);
        if (pTarget!=NULL)
        {
            if (pTarget->size()>2)
            {
                if (pTarget->get(2).asInt()!=0)
                {
                    Vector px(2);
                    px[0]=pTarget->get(0).asDouble();
                    px[1]=pTarget->get(1).asDouble();
                    
                    // FILL IN THE CODE
                }
            }
        }
    }

    void threadRelease()
    {    
        // FILL IN THE CODE

        port.interrupt();
        port.close();
    }
};


class CtrlModule: public RFModule
{
protected:
    CtrlThread *thr;

public:
    bool configure(ResourceFinder &rf)
    {
        Time::turboBoost();
        thr=new CtrlThread(rf);
        if (!thr->start())
        {
            delete thr;
            return false;
        }

        return true;
    }

    bool close()
    {
        thr->stop();
        delete thr;

        return true;
    }

    double getPeriod()    { return 1.0;  }
    bool   updateModule() { return true; }
};



int main(int argc, char *argv[])
{
    // we need to initialize the drivers list 
    YARP_REGISTER_DEVICES(icubmod)

    Network yarp;
    if (!yarp.checkNetwork())
        return -1;    

    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefault("name","tracker");
    rf.setDefault("period","0.02");
    rf.configure(argc,argv);

    CtrlModule mod;
    return mod.runModule(rf);
}



