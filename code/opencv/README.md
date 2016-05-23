Simple YARP program that shows integration with OpenCV.

Besides the YARP libraries you need to have OpenCV installed in your system.

Detect a red ball using Hough transform for circles. It performs basic red pixel detection, edge and circle detection.

Parameters and color filter have been adaptd to work on this image sequence:

http://www.icub.org/download/software/datasetplayer-demo/testData_20120803_095402.zip

Download the sequence and replay it with yarpdataplayer.

Compile and run the example:

```
cd opencv
mkdir build
cmake ../
make make install
```

```
cd ../../bin
./open-cv
```

Connect one of the cameras from the yarpdataplayer (i.e. /icub/camcalib/left/out) to /opencv/image:i and the output to separate viewers.

Images showing detectd edges will be streamed to: /opencv/edges:o

Images showing detected circles will be streamed to: /opencv/circles:o


