#include "remove_background.h"
#include "sort_functions.h"

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

cv::Mat createLightPattern(cv::Mat image)
{
    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(image.cols / 3, image.rows / 3));

    return pattern;
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
    std::cout << nLabels - 1 << " objects detected!" << std::endl;

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
    std::cout << nLabels - 1 << " objects detected!" << std::endl;

    newImage = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);

    int randomColorB = 0;
    int randomColorG = 0;
    int randomColorR = 0;

    std::vector<int> areas;

    for (int i = 1; i < nLabels; i++) {
        randomColorB = (rand() % 255) + 1;
        randomColorG = (rand() % 255) + 1;
        randomColorR = (rand() % 255) + 1;
        cv::Mat mask = labels == i;
        newImage.setTo(cv::Scalar(randomColorB, randomColorG, randomColorR), mask);
        areas.push_back(stats.at<int>(i, cv::CC_STAT_AREA));
    }

    int sortingStepCounter = 0;
    std::vector<int> sortedAreas = selectionSort(areas, sortingStepCounter, 0);

    for (int j = 0; j < sortedAreas.size(); ++j) {
        for (int i = 1; i < nLabels; i++ ) {
            if (stats.at<int>(i, cv::CC_STAT_AREA) == sortedAreas[j]){
                std::string biggest = std::to_string(j + 1);
                cv::putText(newImage, biggest, cv::Point(centroids.at<cv::Point2d>(i)),
                            cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0,0,0), 1, 8, false);
            }
        }
    }
    return newImage;
}

cv::Mat binarizeImageOtsu(cv::Mat image)
{
    cv::Mat newImage;
    cv::threshold(image, newImage, 0, 255, cv::THRESH_OTSU);

    int allPixels = newImage.rows * newImage.cols;
    int whitePixels = cv::countNonZero(newImage);
    int blackPixels = allPixels - whitePixels;

    if(whitePixels < blackPixels)
        return newImage;
    else
        return ~newImage;
}