#ifndef COMPUTER_VISION_BLUR_H
#define COMPUTER_VISION_BLUR_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#define NAME "Computer Vision"

extern cv::Mat gray;
extern cv::Mat blurredImage;
extern int sliderGaussian;
extern int sliderMedian;

void gaussian(int, void *);
void median(int, void *);
void trackbar();

#endif
