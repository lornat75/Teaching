
#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/RpcClient.h>
#include <yarp/os/Time.h>

#include <gsl/gsl_math.h>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using namespace yarp::os;


class Launcher: public RFModule
{
private:
    RpcClient port;
    bool init;    
    double x0;
    double y0;
    double z0;
    int cnt;

public:
    bool configure(ResourceFinder &rf)
    {
        Time::turboBoost();

        string name=rf.find("name").asString().c_str();
        port.open(("/"+name+":o").c_str());

        if (!Network::connect(port.getName().c_str(),"/icubSim/world"))
        {
            cout<<"unable to connect to the world!"<<endl;
            port.close();

            return false;
        }

        x0=0.0;
        y0=1.0;
        z0=0.75;

        init=true;        
        return true;
    }

    bool close()
    {
        port.interrupt();
        port.close();
        return true;
    }

    bool updateModule()
    {
        Bottle cmd,reply;

        if (init)
        {            
            cmd.addString("world");
            cmd.addString("mk");
            cmd.addString("ssph");
            cmd.addDouble(0.03);
            cmd.addDouble(x0);
            cmd.addDouble(y0);
            cmd.addDouble(z0);
            cmd.addDouble(1.0);
            cmd.addDouble(0.0);
            cmd.addDouble(0.0);
            cnt=0;
            init=false;
        }
        else
        {
            double t=(cnt++)*getPeriod();
            double phi=2.0*M_PI*(1.0/20.0)*t;
            double dx=0.3*cos(phi);
            double dy=0.3*sin(phi);
            double dz=0.3*sin(phi);

            cmd.addString("world");
            cmd.addString("set");
            cmd.addString("ssph");
            cmd.addInt(1);
            cmd.addDouble(x0+dx);
            cmd.addDouble(y0+dy);
            cmd.addDouble(z0+dz);
        }

        port.write(cmd,reply);
        return true;
    }

    double getPeriod()
    {
        return 0.1;
    }
};



int main(int argc, char *argv[])
{
    Network yarp;
    if (!yarp.checkNetwork())
        return -1;

    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefault("name","mover");
    rf.configure("ICUB_ROOT",argc,argv);

    Launcher launcher;
    return launcher.runModule(rf);
}


