Running thrift

yarpidl_thrift --gen yarp --out . memory.thrift

Interacting with the server:

yarp rpc /mymodule

>>push "hello" "world"
Response: [ok]
>>get "hello"
Response: [fail]
>>get_answer "hello"
Response: world
>>show_list
Response: [ok]
>>clear
Response: [ok]

Or use the client.


