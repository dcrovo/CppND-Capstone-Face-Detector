#include "FaceDetector.h"
#include "VideoProcessing.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <vector>
static const std::string video_path = "Test.mp4";
int main() {
  VideoProcessing system;
  FaceDetector face_detector;
  std::cout << "Checking if you have an available webcam at device 0..."
            << std::endl;

  if (!system.TryWebcam(0)) {
    std::cout << "It seems that you don't have an available camera device"
              << std::endl;

  } else {
    std::string answer;
    std::cout << "Your camera device is ready, would you like to start the "
                 "face detector? (y) or (n)"
              << std::endl;
    std::cin >> answer;
    if (answer == "y") {
      system.StartCapture(face_detector);

    } else {

      return 0;
    }
  }

  return 0;
}
