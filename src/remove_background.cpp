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
    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(image.cols / 3, image.rows / 3));
    cv::Mat newImage = pattern - image;

    return newImage;
}

cv::Mat binarizeImage(cv::Mat image)
{
    cv::Mat newImage;
    cv::threshold(image, newImage, 57, 255, cv::THRESH_BINARY);

    return newImage;
}

cv::Mat binarizeImageInverse(cv::Mat image)
{
    cv::Mat newImage;
    cv::threshold(image, newImage, 100, 255, cv::THRESH_BINARY_INV);

    return newImage;
}
