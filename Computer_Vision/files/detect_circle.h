#ifndef COMPUTER_VISION_DETECT_CIRCLE_H
#define COMPUTER_VISION_DETECT_CIRCLE_H

#include <iostream>
#include <string.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

extern cv::Mat image;
extern cv::Mat blurredImage;

cv::Mat detectCircle();

#endif
