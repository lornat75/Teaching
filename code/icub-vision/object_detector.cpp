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
    BufferedPort<ImageOf<PixelRgb> > outPortEdges;
    BufferedPort<Bottle> targetPort;

    inPort.open("/objectDetector/image:i");  // give the port a name
    outPort.open("/objectDetector/image:o");

    outPortEdges.open("/objectDetector/edges:o");

    targetPort.open("/objectDetector/target:o");

    while(true)
    {
        ImageOf<PixelRgb> *image = inPort.read();  // read an image

        if (image==NULL)
            continue;

        // check we actually got something
        ImageOf<PixelRgb> &outImage = outPort.prepare(); //get an output image
        outImage.resize(image->width(), image->height());

        ImageOf<PixelRgb> &outEdges = outPortEdges.prepare();
        outEdges.resize(image->width(), image->height());

        //printf("We got an image of size %dx%d\n", image->width(), image->height());
        double xMean = 0;
        double yMean = 0;

        Mat in_cv((IplImage *)image->getIplImage());
        Mat im_gray, detected_edges;
        cvtColor(in_cv,im_gray,CV_BGR2GRAY);
        int kernel_size = 3;

        blur(im_gray, detected_edges, Size(3,3) );
        Canny( detected_edges, detected_edges, 100, 300, kernel_size );

	int count = 0;
        for (int x=0; x<image->width(); x++) {
            for (int y=0; y<image->height(); y++) {


                PixelRgb& pixel = image->pixel(x,y);
                // very simple test for red
                // make sure red level exceeds blue and green by a factor of 2
                // plus some threshold
                int v=pixel.b-pixel.r-pixel.g;

                if (v>30)  //magic number
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

                Scalar intensity = detected_edges.at<uchar>(y, x);
                outEdges(x,y)=PixelRgb(intensity.val[0], intensity.val[0], intensity.val[0]);
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
            target.addInt(1);
        else
            target.addInt(0);    

        targetPort.write();

        outPortEdges.write();
        outPort.write();
    }
    return 0;
}

