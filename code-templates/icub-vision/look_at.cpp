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
    targetPort.open("/lookAt/target:i");

    Property options;
    options.put("device", "remote_controlboard");
    options.put("local", "/lookAt/motor/client");
    options.put("remote", "/icubSim/head");
    PolyDriver robotHead(options);

    if (!robotHead.isValid()) 
    {
        printf("Cannot connect to robot head\n");
        return 1;
    }
    
    IControlMode *mode;
    IPositionControl *pos;
    IVelocityControl *vel;
    IEncoders *enc;
    robotHead.view(pos);
    robotHead.view(vel);
    robotHead.view(enc);
    robotHead.view(mode);

    if (pos==NULL || vel==NULL || enc==NULL || mode==NULL) 
    {
        printf("Cannot get interface to robot head\n");
        robotHead.close();
        return 1;
    }

    int jnts = 0;
    pos->getAxes(&jnts);
    Vector setpoints;
    setpoints.resize(jnts);
    setpoints=0.0; //zero all vetor

   
    while (1) 
    { 
        // repeat forever
        Bottle *target = targetPort.read(); // read a target
        if (target!=NULL) 
        {
        }
    }
    return 0;
}

