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
    cv::threshold(image, newImage, 15, 255, cv::THRESH_BINARY);

    return newImage;
}

cv::Mat binarizeImageInverse(cv::Mat image)
{
    cv::Mat newImage;
    cv::threshold(image, newImage, 15, 255, cv::THRESH_BINARY_INV);

    return newImage;
}


cv::Mat connectComponents(cv::Mat image)
{
    cv::Mat newImage;
    cv::Mat labels;

    int nLabels = cv::connectedComponents(image, labels);
    std::cout << nLabels << " objects detected!" << std::endl;

    newImage = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);

    int randomColorB = 0;
    int randomColorG = 0;
    int randomColorR = 0;

    for (int i = 1; i < nLabels; i++) {
        randomColorB = (rand() % 255) + 1;
        randomColorG = (rand() % 255) + 1;
        randomColorR = (rand() % 255) + 1;
        cv::Mat mask = labels == i;
        newImage.setTo(cv::Scalar(randomColorB, randomColorG, randomColorR), mask);
    }
    return newImage;
}

cv::Mat connectComponentsWithStats(cv::Mat image)
{
    cv::Mat labels;
    cv::Mat newImage;
    cv::Mat stats;
    cv::Mat centroids;

    int nLabels = cv::connectedComponentsWithStats(image, labels, stats, centroids);
    std::cout << nLabels << " objects detected!" << std::endl;

    newImage = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);

    int randomColorB = 0;
    int randomColorG = 0;
    int randomColorR = 0;

    for (int i = 1; i < nLabels; i++) {
        randomColorB = (rand() % 255) + 1;
        randomColorG = (rand() % 255) + 1;
        randomColorR = (rand() % 255) + 1;
        cv::Mat mask = labels == i;
        newImage.setTo(cv::Scalar(randomColorB, randomColorG, randomColorR), mask);
    }
    return newImage;
}
