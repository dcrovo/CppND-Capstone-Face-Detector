#ifndef VIDEOPROCESSING_H
#define VIDEOPROCESSING_H
#include <opencv4/opencv2/opencv.hpp>
#include "FaceDetector.h"




class VideoProcessing{
  public: 
    VideoProcessing();
    void StartCapture(FaceDetector &face_detector);
    void DrawFaces(FaceDetector &face_detector);
    cv::Mat GetFrame();

  private:
    cv::Mat frame_;
    cv::VideoCapture video_capture_;

};

#endif