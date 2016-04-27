#include "Module.h"
#include <yarp/os/Network.h>

int main(int argc, char **argv)
{
    using namespace yarp::os;
    using namespace yarp::sig;

    if (!yarp::os::Network::checkNetwork(5.0)) {
        std::cout << "Yarp network not found\n";
        return false;
    }

    ResourceFinder rf;
    rf.configure(argc, argv);
    Module module;
    
    return module.runModule(rf);
}
