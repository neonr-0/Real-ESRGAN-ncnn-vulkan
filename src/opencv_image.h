#ifndef OPENCV_IMAGE_H
#define OPENCV_IMAGE_H


//OpenCV
#include<opencv2/opencv.hpp>
using namespace cv;


unsigned char* cv_resize_image(unsigned char* in_buf, int height, int weight, int scale_down, int channels)
{
    cv::Mat resized_down;

    int colorScheme = 0;
    if (channels == 4)
        colorScheme = CV_8UC4;
    else
        colorScheme = CV_8UC3;

    cv::Mat inImg = cv::Mat(height, weight, colorScheme, in_buf, cv::Mat::AUTO_STEP);
  
    unsigned char* outimage_bytes = nullptr;
    cv::resize(inImg, resized_down, cv::Size(inImg.cols / scale_down, inImg.rows / scale_down), 0, 0, cv::INTER_LINEAR);
    int sizeCV = resized_down.total() * resized_down.elemSize();
    outimage_bytes = new unsigned char[sizeCV];
    std::memcpy(outimage_bytes, resized_down.data, sizeCV * sizeof(unsigned char));

    inImg.release();
    resized_down.release();
    return outimage_bytes;
}


#endif // OPENCV_IMAGE_H
