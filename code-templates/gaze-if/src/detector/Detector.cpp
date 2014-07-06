
#include "Detector.h"

using namespace yarp::sig;
using namespace yarp::os;

void Detector::loop()
{
    ImageOf<PixelRgb> *image= imagePort.read();  // read an image


    if (image!=NULL) { 

        // check we actually got something
        ImageOf<PixelRgb> &outImage = outPort.prepare(); //get an output image
        outImage=*image;

        //printf("We got an image of size %dx%d\n", image->width(), image->height());
        double xMean = 0;
        double yMean = 0;
        int ct = 0;
        for (int x=0; x<image->width(); x++) {
            for (int y=0; y<image->height(); y++) {
                PixelRgb& pixel = image->pixel(x,y);
                // very simple test for redishness
                // make sure red level exceeds blue and green by a factor of 2
                // plus some threshold
                if ((pixel.r>pixel.b*5.0) && (pixel.r>pixel.g*5.0)) {
                    // there's a redish pixel at (x,y)!
                    // let's find the average location of these pixels

                    // accumulate x
                    // accumulate y
                    // count total number of points
                    xMean += x;
                    yMean += y;
                    ct++;

                    outImage(x,y).r=255;
                }
            }
        }
        if (ct>0) {
            xMean /= ct;
            yMean /= ct;
        }

        Bottle &target=targetPort.prepare();
        target.clear();
        target.addDouble(xMean);
        target.addDouble(yMean);

        //threshold on the size of the object we found
        if (ct>(image->width()/20)*(image->height()/20))
        {
            target.addInt(1);
        }
        else
        {
            target.addInt(0);
        }

        targetPort.write();

        outPort.write();
    }
}

bool Detector::open()
{
    bool ret=true;
    ret=imagePort.open("/detector/image/in");  // give the port a name
    ret = ret && outPort.open("/detector/image/out");
    ret = ret && targetPort.open("/detector/target");

    return ret;
}

bool Detector::close()
{
    Bottle &target=targetPort.prepare();
    target.clear();
    target.addDouble(0);
    target.addDouble(0);

    target.addInt(0);    
    
    targetPort.setStrict();
    targetPort.write();
    

    outPort.write();

    imagePort.close();
    outPort.close();
    targetPort.close();

    return true;
}

bool Detector::interrupt()
{
    imagePort.interrupt();
    return true;
}

