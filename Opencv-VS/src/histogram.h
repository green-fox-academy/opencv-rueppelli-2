#ifndef COMPUTER_VISION_HISTOGRAM_H
#define COMPUTER_VISION_HISTOGRAM_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat histogram(cv::Mat input);
cv::Mat normalizeColoring(cv::Mat img);

#endif
