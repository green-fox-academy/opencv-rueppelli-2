#ifndef COMPUTER_VISION_EDGE_DETECTION_H
#define COMPUTER_VISION_EDGE_DETECTION_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "remove_background.h"

cv::Mat binarizeImage(cv::Mat image, cv::Mat pattern);
cv::Mat binarizeImageInverse(cv::Mat image, cv::Mat pattern);

#endif
