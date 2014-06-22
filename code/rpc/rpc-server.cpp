// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
This is an example of using a specialized RpcServer port to receive
and reply to messages.  Regular YARP ports can do this as well (see
summer.cpp), but use of RpcServer/RpcClient allows for better
run-time checking of port usage to catch mistakes.
 */
#include <yarp/os/all.h>
#include <stdio.h>
using namespace yarp::os;
int main(int argc, char *argv[]) {
    Network yarp;
    RpcServer port;
    port.open("/server");
    while (true) {
        printf("Waiting for a message...\n");
        Bottle cmd;
        Bottle response;
        port.read(cmd,true);
        printf("Got message: %s\n", cmd.toString().c_str());
        response.addString("you");
        response.addString("said");
        response.append(cmd);
        printf("Sending reply: %s\n", response.toString().c_str());
        port.reply(response);
    }
}

