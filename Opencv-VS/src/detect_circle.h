#ifndef COMPUTER_VISION_DETECT_CIRCLE_H
#define COMPUTER_VISION_DETECT_CIRCLE_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "histogram.h"

int detectCircle(cv::Mat &image);

#endif
