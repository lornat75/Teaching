// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include <stdio.h>
#include <yarp/os/Network.h>


#include "Detector.h"
#include <yarp/os/RFModule.h>

using namespace yarp::os;

class DetectorModule: public RFModule
{
   Detector detector;
public:

    bool configure(ResourceFinder &rf)
    {
        return detector.open();
    }

    double getPeriod()
    {
        return 0.0;
    }
    
    bool updateModule()
    { 
        detector.loop();
        return true; 
    }

    bool interruptModule()
    {
        fprintf(stderr, "Interrupting\n");
        detector.interrupt();
        return true;
    }

    bool close()
    {
        fprintf(stderr, "Calling close\n");
        detector.close();
        return true;
    }

    //void respond();

};

int main(int argc, char *argv[]) 
{
    Network yarp;

    DetectorModule module;
    ResourceFinder rf;

    if (!module.configure(rf))
    {
        fprintf(stderr, "Error configuring module returning\n");
        return 1;
    }


    module.runModule();

    printf("Module shutting down\n");

    return 0;
}