This folder contains an example of use of the [WholeBodyInterface (WBI)](https://github.com/robotology/wholebodyinterface).

To install the dependencies please use the [Codyco superbuild](https://github.com/robotology/codyco-superbuild).

Any issues related to the use of the WBI should be opened in the respective repository (either [here](https://github.com/robotology/wholebodyinterface/issues) or [here](https://github.com/robotology/yarp-wholebodyinterface/issues)).


###Running the example

This example shows a simple use of the whole body interface.
It implements a PD plus gravity compensation (which in its nature is quite generic), but references are targeted to the iCub robot.

The folder also contains the urdf model of iCub and a configuration file to use the wbi with the model.
This has been done to make this module independent from the configuration files shipped in the codyco-superbuild, but it is not meant to be used as a real-world scenario module.

Once you compiled the example

```
mkdir build
cd build
cmake ..
make
```

you can launch it by specifying the configuration files:

```
./WBI_example --wbi_config_file ../wbi-config.ini
```