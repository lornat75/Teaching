#include <stdio.h>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;
int main() {
    Network yarp; // set up yarp
    BufferedPort<Bottle> targetPort;
    targetPort.open("/mover/target/in");
    // Network::connect("/objectDetector/target","/mover/target/in");
    // Network::connect("/tracker/target:o","/mover/target/in");
    Property options;
    options.put("device", "remote_controlboard");
    options.put("local", "/mover/motor/client");
    options.put("remote", "/icubSim/head");
    PolyDriver robotHead(options);

    if (!robotHead.isValid()) 
    {
        printf("Cannot connect to robot head\n");
        return 1;
    }
    
    IPositionControl *pos;
    IVelocityControl *vel;
    IEncoders *enc;
    robotHead.view(pos);
    robotHead.view(vel);
    robotHead.view(enc);
	
	ivel->setVelocityMode();
	
    if (pos==NULL || vel==NULL || enc==NULL) 
    {
        printf("Cannot get interface to robot head\n");
        robotHead.close();
        return 1;
    }
    int jnts = 0;
    pos->getAxes(&jnts);
    Vector setpoints;
    setpoints.resize(jnts);
    while (1) 
    { // repeat forever
        Bottle *target = targetPort.read(); // read a target
        if (target!=NULL) 
        { // check we actually got something
          //move the head
        }
    }
    return 0;
}

