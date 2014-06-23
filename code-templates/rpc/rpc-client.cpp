// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
This is an example of using a specialized RpcClient port to send
messages and receive replies.  Regular YARP ports can do this as well,
but use of RpcServer/RpcClient allows for better
run-time checking of port usage to catch mistakes.
 */
#include <yarp/os/all.h>
#include <stdio.h>
#include <string>

using namespace std;
using namespace yarp::os;
int main(int argc, char *argv[]) {
    Network yarp;

}