#include "blur.h"

void gaussian(int, void *)
{
    cv::GaussianBlur(gray, blurredImage, cv::Size(2*sliderGaussian+1, 2*sliderGaussian+1), sliderGaussian);
    imshow(NAME, blurredImage);
}
void median(int, void *)
{
    cv::medianBlur(gray, blurredImage, 2 * sliderMedian + 1);
    imshow(NAME, blurredImage);
}

void trackbar()
{
    cv::createTrackbar("Gaussian Blur", NAME, &sliderGaussian, 25, gaussian);
    gaussian(1, nullptr);
    cv::createTrackbar("Median Blur", NAME, &sliderMedian, 25, median);
    median(1, nullptr);
}
