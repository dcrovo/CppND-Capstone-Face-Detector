#ifndef VIDEOPROCESSING_H
#define VIDEOPROCESSING_H
#include <opencv4/opencv2/opencv.hpp>
#include "FaceDetector.h"




class VideoProcessing{
  public: 
    VideoProcessing();
    VideoProcessing(std::string video_path);
    void StartCapture(FaceDetector &face_detector);
    void StartCapture(FaceDetector &face_detector, std::string path);

    void DrawFaces(FaceDetector &face_detector);
    bool TryWebcam(int index_cam);
    cv::Mat GetFrame();

  private:
    cv::Mat frame_;
    cv::VideoCapture video_capture_;

};

#endif