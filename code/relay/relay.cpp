#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>

#include <yarp/os/all.h>

using namespace std;
using namespace yarp::os;

int main(int argc, const char **argv) {
    Network yarp;
    Port inPort;
    if (!inPort.open("/relay/in"))
	{
		fprintf(stderr, "error opening port");
		return -1;
	}

    Port outPort;
    outPort.open("/relay/out");

    int counter=0;
    while (true) {
        counter++;

        cout << "waiting for input" << endl;
        Bottle input,output;
        inPort.read(input);
        
        output.addInt(counter);
        output.addString("Data was received and parsed by relay");
		output.addList()=input;
		
        cout << "writing " << output.toString().c_str() << endl;
        outPort.write(output);
    }
    return 0;
}
