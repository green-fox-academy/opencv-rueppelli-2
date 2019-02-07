#include "edge_detection.h"

cv::Mat detectEdge(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = removeLightWithDivision(image, pattern);
    cv::threshold(image, newImage, 57, 255, cv::THRESH_BINARY);

    return newImage;
}
