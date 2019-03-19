#ifndef COMPUTER_VISION_DETECT_CIRCLE_H
#define COMPUTER_VISION_DETECT_CIRCLE_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "img_histogram.h"
#include "sort_functions.h"

int detectCircle(cv::Mat &image);

cv::Mat connectComponentsWithStats(cv::Mat image);

void detectFeaturePointsAKAZE();
void detectFeaturePointsFFD();

#endif
