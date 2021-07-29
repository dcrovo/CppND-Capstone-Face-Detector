# CPPND: Capstone Face Detection Application

This project is an implemetation of a application for recognizing faces and drawing rectangles around them in real time with the image of a webcam:

It consist of 2 clases and main:
VideoProcessing which is doing the capturing of the video and drawing 
FaceDetector which uses a ResNet-10 neurarl network pre trained model form Caffe

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* OpenCV >= 1.4
  * Linux: click here for installation instructions


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./face_detector.

## Rubic points addressed
* The project demonstrates an understanding of C++ functions and control structures.
* The project uses Object Oriented Programming techniques.
* Classes use appropriate access specifiers for class members.
* Class constructors utilize member initialization lists.
* The project makes use of references in function declarations.


## Atributions
  This project is based on the explanation given in this webpage
1. https://learnopencv.com/face-detection-opencv-dlib-and-deep-learning-c-python/
