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

    if (pos == NULL || vel == NULL || enc == NULL || mode == NULL)
    {
        printf("Cannot get interface to robot head\n");
        robotHead.close();
        return 1;
    }

    int jnts = 0;
    pos->getAxes(&jnts);
    Vector setpoints;
    setpoints.resize(jnts);

    // go to zero
    // set all joints to position mode
    for (int j = 0; j < jnts; j++)
        mode->setPositionMode(j);

    setpoints = 0.0;
    // move joints
    pos->positionMove(setpoints.data());
    bool done = false;
    printf("Parking head...");
    // wait until motion is completed
    while (!done)
    {
        pos->checkMotionDone(&done);
        printf(".");
    }
    printf("\n");

    //wait until first data is received
    Bottle *target = targetPort.read();

    for (int j = 0; j < jnts; j++)
        mode->setVelocityMode(j);

    while (1)
    {
        // repeat forever
        Bottle *target = targetPort.read(); // read a target
        if (target != NULL)
        { // check we actually got something
            printf("We got a vector containing");
            for (int i = 0; i < target->size(); i++)
            {
                printf(" %g", target->get(i).asDouble());
            }
            printf("\n");
            double x = target->get(0).asDouble();
            double y = target->get(1).asDouble();
            double conf = target->get(2).asInt();
            x -= 320 / 2;
            y -= 240 / 2;
            double vx = x*0.7;
            double vy = -y*0.7;
            /* prepare command */
            for (int i = 0; i < jnts; i++)
            {
                setpoints[i] = 0;
            }
            if (conf > 0)
            {
                setpoints[3] = vy;
                setpoints[4] = vx;
            }
            else
            {
                setpoints[3] = 0;
                setpoints[4] = 0;
            }
            vel->velocityMove(setpoints.data());
        }
    }
    return 0;
}

