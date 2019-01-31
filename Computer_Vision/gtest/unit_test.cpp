#include <gtest/gtest.h>
#include "initial.h"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

TEST(test_check, test_cuccok){
    cv::Mat img;
    EXPECT_EQ(initialFunction(1, 1), 2);
}