#include "FaceDetector.h"
#include "VideoProcessing.h"
#include <iostream>
#include <opencv2/dnn/dnn.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <vector>

int main() {
  VideoProcessing system;
  FaceDetector face_detector;
  system.StartCapture(face_detector);

  return 0;

  
}
