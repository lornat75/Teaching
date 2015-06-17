#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>

#include <yarp/os/all.h>

using namespace std;
using namespace yarp::os;

int main(int argc, char *argv[]) {
    Network yarp;
    BufferedPort<Bottle> outPort;
    if (!outPort.open("/producer"))
    {
        fprintf(stderr, "error opening port");
        return -1;
    }

    int counter=0;
    while (true) {
        counter++;

        Bottle &message=outPort.prepare();
        message.clear(); //important, objects get recycled
        message.addInt(counter);
        message.addString("Hello from producer");
        
        outPort.write();
        printf("[%d] written message\n", counter);
        Time::delay(0.1);
    }
    return 0;
}
