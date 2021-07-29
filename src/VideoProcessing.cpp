#include "VideoProcessing.h"
#include "FaceDetector.h"
#include <opencv4/opencv2/opencv.hpp>

VideoProcessing::VideoProcessing() {}
void VideoProcessing::StartCapture(FaceDetector &face_detector) {

  if(!video_capture_.open(0)) {
    return;
  }

  while (true) {
    video_capture_ >> frame_;
    face_detector.Detect(frame_);
    DrawFaces(face_detector);
    imshow("Image", frame_);
    int esc_key = 27;
    if (cv::waitKey(10) == esc_key) {
      break;
    }
  }

  cv::destroyAllWindows();
  video_capture_.release();
}

void VideoProcessing::DrawFaces(FaceDetector &face_detector) {
  auto rectangles = face_detector.GetFaces();
  cv::Scalar color(90, 105, 205);
  for (const auto &r : rectangles) {
    cv::rectangle(frame_, r, color, 4);
  }
}
