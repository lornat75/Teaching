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
	
	inPort.open("/objectDetector/image/in");  // give the port a name
    outPort.open("/objectDetector/image/out");
    targetPort.open("/objectDetector/target");
		  
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

