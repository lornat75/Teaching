#ifndef MODULE_H
#define MODULE_H

#include <yarp/os/RFModule.h>
#include <yarp/sig/Vector.h>

namespace wbi {
    class wholeBodyInterface;
}

class Module : public yarp::os::RFModule
{
    wbi::wholeBodyInterface* m_robot;
    yarp::sig::Vector positions;
    yarp::sig::Vector velocities;
    yarp::sig::Vector gravityCompensation;
    yarp::sig::Vector referencePositions;
        
    //write
    yarp::sig::Vector error;
    yarp::sig::Vector kp;
    yarp::sig::Vector kd;
    yarp::sig::Vector torques;
    yarp::sig::Vector zeroDofs;
    yarp::sig::Vector baseZeroDofs;
    yarp::sig::Vector grav;
    
public:
    virtual double getPeriod ();
    virtual bool updateModule ();
    virtual bool configure (yarp::os::ResourceFinder &rf);
    virtual bool close ();
};


#endif /* end of include guard: MODULE_H */
