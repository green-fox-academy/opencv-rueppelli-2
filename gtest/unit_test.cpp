#include <gtest/gtest.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "detect_circle.h"

TEST(DetectCircles, noCircle)
{
    cv::Mat image = cv::imread("../../img/noCircle.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 0);
}

TEST(DetectCircles, numerousCircles)
{
    cv::Mat image = cv::imread("../../img/ball.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 3);
}

TEST(DetectCircles, overlayCircles)
{
    cv::Mat image = cv::imread("../../img/balls11.jpg", cv::IMREAD_GRAYSCALE);
    EXPECT_EQ(detectCircle(image), 3);
}
