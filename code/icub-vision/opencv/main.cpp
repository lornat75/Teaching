#include <yarp/sig/Image.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/sig/Vector.h>

#include <cv.h>
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;

class MyModule:public RFModule
{
    Port handlerPort; //a port to handle messages
	BufferedPort<ImageOf<PixelRgb>  >   imageIn;
    BufferedPort<Bottle>                targetPort;
    BufferedPort<ImageOf<PixelMono>  >  imageOut;
    cv::Mat                             color;

public:

    double getPeriod()
    {
        return 0.1; //module periodicity (seconds)
    }

    cv::Mat blueFilter(const cv::Mat& src)
    {
        assert(src.type() == CV_8UC3);

        cv::Mat blueOnly;
        cv::inRange(src, cv::Scalar(0, 0, 0), cv::Scalar(0, 0, 255), blueOnly);

        return blueOnly;
    }

    bool updateModule()
    {
        if (imageIn.getInputCount()>0)
        {
            cv::Mat orig = cv::cvarrToMat((IplImage *) imageIn.read(true)->getIplImage());
            ImageOf<PixelMono> &outImg = imageOut.prepare();

            cv::Mat blueOnly = blueFilter(orig);
            
            float sumx=0, sumy=0;
            float num_pixel = 0;
            for(int x=0; x<blueOnly.cols; x++) {
                for(int y=0; y<blueOnly.rows; y++) {
                    int val = blueOnly.at<uchar>(y,x);
                    if( val >= 50) {
                        sumx += x;
                        sumy += y;
                        num_pixel++;
                    }
                }
            }
            cv::Point p(sumx/num_pixel, sumy/num_pixel);
            //cout << cv::Mat(p) << endl;

            cv::Moments m = cv::moments(blueOnly, false);
            cv::Point p1(m.m10/m.m00, m.m01/m.m00);
            //cout << cv::Mat(p1) << endl;

            cv::circle(blueOnly, p, 5, cv::Scalar(0,0,0), -1);

            Bottle &target=targetPort.prepare();
            target.clear();
            

            if (p.x < 0 && p.y <0) 
            {
                target.addDouble(0);
                target.addDouble(0);
                target.addInt(0);
            }            
            else
            {
                target.addDouble(p.x);
                target.addDouble(p.y);
                target.addInt(1);
            }

            IplImage tmp = blueOnly;
            outImg.resize(tmp.width, tmp.height);
            cvCopyparalle( &tmp, (IplImage *) outImg.getIplImage());
            imageOut.write();

            targetPort.write();
        }
        return true;
    }

    bool respond(const Bottle& command, Bottle& reply) 
    {
        cout<<"Got something, echo is on"<<endl;
        if (command.get(0).asString()=="quit")
            return false;
        else
            reply=command;
        return true;
    }

    /* 
    * Configure function. Receive a previously initialized
    * resource finder object. Use it to configure your module.
    * Open port and attach it to message handler.
    */
    bool configure(yarp::os::ResourceFinder &rf)
    {
        string moduleName = "tracker";

        string handleportString = "/" + moduleName;
        handlerPort.open(handleportString.c_str());

        string inputNameImage = "/" + moduleName + "/image:i";
        imageIn.open( inputNameImage.c_str() );

        string outputNameImage = "/" + moduleName + "/image:o";
        imageOut.open( outputNameImage.c_str() );

        string outputNameTarget = "/" + moduleName + "/target:o";
        targetPort.open(outputNameTarget.c_str());

        attach(handlerPort);

        return true;
    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module, for port cleanup"<<endl;
        return true;
    }

    /*
    * Close function, to perform cleanup.
    */
    bool close()
    {
        cout<<"Calling close function\n";
        handlerPort.close();
        imageIn.interrupt();
        imageIn.close();
        imageOut.close();
        targetPort.close();
        
        return true;
    }
};

int main(int argc, char * argv[])
{
    Network yarp;

    MyModule module;
    ResourceFinder rf;
    rf.configure(argc, argv);
    rf.setVerbose(true);

    cout<<"Configure module..."<<endl;
    module.configure(rf);
    cout<<"Start module..."<<endl;
    module.runModule();

    cout<<"Main returning..."<<endl;
    return 0;
}



