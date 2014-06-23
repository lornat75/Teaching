#include <iostream>
#include <string>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>

#include <yarp/os/all.h>

using namespace std;
using namespace yarp::os;

int main(int argc, char *argv[]) {
    Network yarp;
    
	// BufferedPort<Bottle> inPort;

    ResourceFinder parameters;
    parameters.configure(argc, argv);

    int delay=0;
    string portname="/consumer";

    if (parameters.check("name"))
        portname=parameters.find("name").asString().c_str();

    if (parameters.check("delay"))
    {
        delay=parameters.find("delay").asInt();
        printf("Setting delay to %d[ms]\n", delay);
    }

    inPort.open(portname.c_str());

    while (true) {

    }
    return 0;
}
