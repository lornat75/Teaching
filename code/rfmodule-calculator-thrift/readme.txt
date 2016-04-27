Running thrift

yarpidl_thrift --gen yarp --out . calculator.thrift

Interacting with the server:

yarp rpc /mymodule
>> sum 3 4 


