#include "FaceDetector.h"
#include <iostream>
#include <opencv2/dnn/dnn.hpp>
#include <vector>

FaceDetector::FaceDetector()
    : inWidth_(300), inHeight_(300), mean_({104., 177.0, 123.0}),
      scalefactor_(1.0), confidence_tresshold_(0.7) {

  model_ = cv::dnn::readNetFromCaffe(caffeConfigFile, caffeWeigthFile);
  if (model_.empty()) {
    throw std::invalid_argument("Failed to load network");
  }
}

std::vector<cv::Rect> FaceDetector::Detect(cv::Mat &frame) {

  cv::Mat inputBlob = cv::dnn::blobFromImage(
      frame, scalefactor_, cv::Size(inWidth_, inHeight_), mean_, false, false);

  model_.setInput(inputBlob, "data");
  cv::Mat result = model_.forward("detection_out");
  cv::Mat resultMatrix(result.size[2], result.size[3], CV_32F,
                       result.ptr<float>());
  std::vector<cv::Rect> faces;
  for (int i = 0; i < resultMatrix.rows; i++) {
    float confidence = resultMatrix.at<float>(i, 2);
    if (confidence < confidence_tresshold_){

      int x1 = static_cast<int>(resultMatrix.at<float>(i, 3) * frame.cols);

      int y1 = static_cast<int>(resultMatrix.at<float>(i, 4) * frame.rows);

      int x2 = static_cast<int>(resultMatrix.at<float>(i, 5) * frame.cols);

      int y2 = static_cast<int>(resultMatrix.at<float>(i, 6) * frame.rows);

      faces.emplace_back(x1, y2, (x2 - x1), (y2 - y1));

    }
  }
  return faces;
}
