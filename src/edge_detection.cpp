#include "edge_detection.h"

cv::Mat binarizeImage(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = removeLightWithDivision(image, pattern);
    cv::threshold(image, newImage, 57, 255, cv::THRESH_BINARY);

    return newImage;
}

cv::Mat binarizeImageInverse(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = removeLightWithDivision(image, pattern);
    cv::threshold(image, newImage, 57, 255, cv::THRESH_BINARY_INV);

    return newImage;
}
