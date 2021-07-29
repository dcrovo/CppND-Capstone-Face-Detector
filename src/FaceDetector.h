#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H
#include <opencv2/dnn/dnn.hpp>

//path to the configuration and weigth files of the pre trained neural network
const static std::string caffeConfigFile = "../data/deploy.prototxt";
const static std::string caffeWeigthFile = "../data/res10_300x300_ssd_iter_140000_fp16.caffemodel";

class FaceDetector{
  public: 
    FaceDetector();
    std::vector<cv::Rect> Detect(cv::Mat &frame);
    void Draw(cv::Mat &frame);

  private:
    cv::dnn::Net model_;
    const int inWidth_;
    const int inHeight_;
    const cv::Scalar mean_;
    const double scalefactor_;
    float confidence_tresshold_;

};

#endif