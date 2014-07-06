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

        // check we actually got something
        ImageOf<PixelRgb> &outImage = outPort.prepare(); //get an output image
        outImage.resize(image->width(), image->height());
		
        //printf("We got an image of size %dx%d\n", image->width(), image->height());
        double xMean = 0;
        double yMean = 0;
        int count = 0;
        for (int x=0; x<image->width(); x++) {
            for (int y=0; y<image->height(); y++) {
                PixelRgb& pixel = image->pixel(x,y);
                // very simple test for red
                // make sure red level exceeds blue and green by a factor of 2
                // plus some threshold
				int v=pixel.b-pixel.r-pixel.g;
				
				if (v>40)  //magic number
				{
                    // there's a blue pixel at (x,y)!
                    // let's find the average location of these pixels

                    // accumulate x
                    // accumulate y
                    // count total number of points
                    xMean += x;
                    yMean += y;
                    count++;

                    outImage(x,y)=pixel;
                }
                else
                {
                    outImage(x,y)=PixelRgb(0,0,0);
                }
            }
        }
        if (count>0) {
            xMean /= count;
            yMean /= count;
        }

        Bottle &target=targetPort.prepare();
        target.clear();
        target.addDouble(xMean);
        target.addDouble(yMean);
		
        //threshold on the size of the object we found
        if (count>(image->width()/20)*(image->height()/20))
        {
            target.addInt(1);
        }
        else
            target.addInt(0);    

		//target.addInt(image->width());
		//target.addInt(image->height());
		
        targetPort.write();

        outPort.write();
    }
	return 0;
}

