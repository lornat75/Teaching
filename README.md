This repository contains various tutorials used to teach programming with YARP and the iCub.

The organization is the following.

### Code directory

Contains all the code and working examples. To compile just go in the source directory of an individual tutorial and run cmake.

E.g. in Linux:

```
cd producer-consumer
mkdir build
cmake ../
make 
make install
```

In windows with Visual Studio you can compile at the command line using the following commands:

```
cmake --build ./ --target INSTALL
```

Notice that binaries for all tutorials will be installed in the directory bin.

### Code-templates

This folder contains the same tutorials, with partially incompete files. It is used as starting point for students to follow and complete the tutorials during classes.


