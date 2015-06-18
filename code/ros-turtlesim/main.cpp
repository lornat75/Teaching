#include "Pose.h"
#include "Twist.h"
#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>

#include <yarp/os/Node.h>
#include <yarp/os/Subscriber.h>
#include <yarp/os/Publisher.h>

using namespace std;
int main()
{
   yarp::os::Network network;

   yarp::os::Node node("/controller");   // added a Node
   yarp::os::Subscriber<Pose> pose;
   yarp::os::Publisher<Twist> cmd;

   if (!pose.topic("/turtle1/pose"))
   {
       cerr<<"Error opening topic, check your network\n";
       return -1;
   }

   if (!cmd.topic("/turtle1/cmd_vel"))
   {
       cerr<<"Error opening topic, check your network\n";
       return -1;
   }

   cout<<"Starting sender\n";

   while(true)
   {
      //read and print pose
      Pose p;
      pose.read(p);

      cout<<p.x<<" " << p.y << " " << p.theta << "\n";
      cout<<p.linear_velocity<<" " << p.angular_velocity << "\n";
      cout<<"==========\n";

      // make a circle
      Twist t;
      t.linear.x=1.0;
      t.linear.y=0.0;
      t.linear.z=0.0;

      t.angular.x=0.0;
      t.angular.y=0.0;
      t.angular.z=1;
      
      cmd.write(t);

      yarp::os::Time::delay(0.1);
   }
   return 0;
}
