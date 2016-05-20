#include <stdio.h>

#include <yarp/os/all.h>
#include <yarp/sig/all.h>

using namespace yarp::os;
using namespace yarp::sig;

#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main() {
    Network yarp;

    BufferedPort<ImageOf<PixelRgb> > inPort;  // make a port for reading images
    BufferedPort<ImageOf<PixelRgb> > outPort;

    inPort.open("/opencv/image:i");  // give the port a name
    outPort.open("/opencv/image:o");

    while(true)
    {
        ImageOf<PixelRgb> *image = inPort.read();  // read an image
        ImageOf<PixelRgb> &outImage = outPort.prepare(); 
        

	outPort.write();
    }
    return 0;
}

