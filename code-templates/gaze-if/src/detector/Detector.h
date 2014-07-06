
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Image.h>

class Detector
{
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > imagePort;  // make a port for reading images
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > outPort;
    yarp::os::BufferedPort<yarp::os::Bottle> targetPort;

public:

    Detector()
    {
        // constructor
    }

    bool open();

    bool close();

    void loop(); 

    bool interrupt();

};

   
   



   