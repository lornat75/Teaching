#include <stdio.h>

#include <yarp/os/all.h>
#include <yarp/sig/all.h>

using namespace yarp::os;
using namespace yarp::sig;

#include <cv.h>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

const int CANNY_HIGH_THRESHOLD=80;
const int HOUGH_MIN_VOTES=15;
const int HOUGH_MIN_RADIUS=10;
const int HOUGH_MAX_RADIUS=60;


int main() {
    Network yarp;

    BufferedPort<ImageOf<PixelRgb> > inPort;  // make a port for reading images
    BufferedPort<ImageOf<PixelRgb> > outPort;
    BufferedPort<ImageOf<PixelMono> > edgesPort;


    inPort.open("/opencv/image:i");  // give the port a name
    outPort.open("/opencv/circles:o");
    edgesPort.open("/opencv/edges:o");
	

    Mat im_gray;

    while(true)
    {
        ImageOf<PixelRgb> *image = inPort.read();  // read an image
        ImageOf<PixelRgb> &outCircles = outPort.prepare(); 
	ImageOf<PixelMono> &outEdges = edgesPort.prepare();
        

        if (image==NULL)
            continue;

	outCircles.resize(image->width(), image->height());
	outEdges.resize(image->width(), image->height());

	outCircles=*image;


	// look for red pixels assuming you are looking for a red ball
	for (int x=0; x<image->width(); x++) {
            for (int y=0; y<image->height(); y++) {
                PixelRgb& pixel = image->pixel(x,y);
		int val=pixel.r-pixel.g-pixel.b;
		if (val<100)
			{
				pixel.r=0;
				pixel.g=0;
				pixel.b=0;
			}
		}
	}

        Mat in_cv((IplImage *)image->getIplImage());
        cvtColor(in_cv,im_gray,CV_RGB2GRAY);

	Mat detected_edges((IplImage *)outEdges.getIplImage());
	Mat out_circles((IplImage *)outCircles.getIplImage());
 
	int kernel_size = 3;
        Canny( im_gray, detected_edges, CANNY_HIGH_THRESHOLD/2, CANNY_HIGH_THRESHOLD, kernel_size );

	vector<Vec3f> circles;
  	/// Apply the Hough Transform to find the circles
  	HoughCircles( im_gray, circles, CV_HOUGH_GRADIENT, 1, im_gray.rows/8, 
			CANNY_HIGH_THRESHOLD, HOUGH_MIN_VOTES, HOUGH_MIN_RADIUS, HOUGH_MAX_RADIUS );

	cout<<"Found "<<circles.size()<<" circles\n";
	/// Draw the circles detected
  	for( size_t i = 0; i < circles.size(); i++ )
  	{
      		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      		int radius = cvRound(circles[i][2]);
      		// circle center
      		circle( out_circles, center, 3, Scalar(0,255,0), -1, 8, 0 );
      		// circle outline
      		circle( out_circles, center, radius, Scalar(0,0,255), 3, 8, 0 );
   	}

#if 0
	for (int x=0; x<outImage.width(); x++) {
            for (int y=0; y<outImage.height(); y++) {
                PixelRgb& pixel = outImage.pixel(x,y);
	
		Vec3b bgrPixel = in_cv.at<Vec3b>(y, x);
		pixel.r=bgrPixel[0];
		pixel.g=bgrPixel[1];
		pixel.b=bgrPixel[2];
		}
	}
#endif 


#if 0
	for (int x=0; x<outImage.width(); x++) {
            for (int y=0; y<outImage.height(); y++) {
                PixelRgb& pixel = outEdges.pixel(x,y);
	
		Scalar intensity = detected_edges.at<uchar>(y, x);
		pixel.r=intensity.val[0];
		pixel.g=intensity.val[0];
		pixel.b=intensity.val[0];
		}
	}
#endif


	outPort.write();
	edgesPort.write();
    }
    return 0;
}

