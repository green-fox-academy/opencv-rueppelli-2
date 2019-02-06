#ifndef COMPUTER_VISION_REMOVE_BACKGROUND_H
#define COMPUTER_VISION_REMOVE_BACKGROUND_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat removeLightWithDifference(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithBlur(cv::Mat image);

#endif
