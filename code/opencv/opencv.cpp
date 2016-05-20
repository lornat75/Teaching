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

    Mat im_gray, detected_edges;

    while(true)
    {
        ImageOf<PixelRgb> *image = inPort.read();  // read an image
        ImageOf<PixelRgb> &outImage = outPort.prepare(); 
        

        if (image==NULL)
            continue;

	outImage.resize(image->width(), image->height());

        Mat in_cv((IplImage *)image->getIplImage());
        cvtColor(in_cv,im_gray,CV_RGB2GRAY);
        
	int kernel_size = 3;
        blur(im_gray, detected_edges, Size(3,3) );

        Canny( detected_edges, detected_edges, 100, 300, kernel_size );

	for (int x=0; x<outImage.width(); x++) {
            for (int y=0; y<outImage.height(); y++) {
                PixelRgb& pixel = outImage.pixel(x,y);
	
		Scalar intensity = detected_edges.at<uchar>(y, x);
		pixel.r=intensity.val[0];
		pixel.g=intensity.val[0];
		pixel.b=intensity.val[0];
		}
	}

	outPort.write();
    }
    return 0;
}

