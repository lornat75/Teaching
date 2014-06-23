#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>

#include <yarp/os/all.h>

using namespace std;
using namespace yarp::os;

int main(int argc, char *argv) {
    Network yarp;
    // BufferedPort<Bottle> outPort;
    if (!outPort.open("/producer"))
    {
        fprintf(stderr, "error opening port");
        return -1;
    }

    int counter=0;
    while (true) {
 
    }
    return 0;
}
