#ifndef COMPUTER_VISION_REMOVE_BACKGROUND_H
#define COMPUTER_VISION_REMOVE_BACKGROUND_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "sort_functions.h"

cv::Mat removeLightWithDifference(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern);
cv::Mat createLightPattern(cv::Mat image);

cv::Mat binarizeImage(cv::Mat image);

cv::Mat sharpen (cv::Mat image);

cv::Mat normalizeColoring(cv::Mat img);

#endif
