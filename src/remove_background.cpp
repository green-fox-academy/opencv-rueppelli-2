#include "remove_background.h"

cv::Mat removeLightWithDifference(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = pattern - image;
    return newImage;
}

cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = 255 * (1 - (pattern / image));
    return newImage;
}

cv::Mat removeLightWithBlur(cv::Mat image)
{
    int max = 75;
    int kernelSize = 2 * max + 1;

    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(kernelSize, kernelSize), cv::Point(-1));
    cv::Mat newImage = pattern - image;

    return newImage;
}
