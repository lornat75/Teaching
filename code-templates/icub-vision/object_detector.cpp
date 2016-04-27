#include <stdio.h>

#include <yarp/os/all.h>
#include <yarp/sig/all.h>

using namespace yarp::os;
using namespace yarp::sig;

int main() {
    Network yarp;

    BufferedPort<ImageOf<PixelRgb> > inPort;  // make a port for reading images
    BufferedPort<ImageOf<PixelRgb> > outPort;
    BufferedPort<Bottle> targetPort;

    inPort.open("/objectDetector/image:i");  // give the port a name
    outPort.open("/objectDetector/image:o");
    targetPort.open("/objectDetector/target:o");

    while(true)
    {
        ImageOf<PixelRgb> *image = inPort.read();  // read an image

        if (image==NULL)
            continue;

        //do processing
        targetPort.write();

        outPort.write();
    }
    return 0;
}

