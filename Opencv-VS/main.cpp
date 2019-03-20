#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "sqlite_functions.h"
#include "img_detection.h"
#include "sort_functions.h"
#include "img_filtering.h"
#include "img_histogram.h"

#define WINDOW_NAME "Computer Vision"

void gaussian(int, void *);
void median(int, void *);
void trackbar();

cv::Mat image;
cv::Mat blurredImage;
int sliderGaussian = 0;
int sliderMedian = 0;

int main(int argc, char* argv[]) {

    srand(time(nullptr));

    sqlite3* db;
    int rc = sqlite3_open(argv[1], &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_open(argv[1], &db);

    image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    if(!image.data) {
        std::cout << "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }

    namedWindow(WINDOW_NAME, cv::WINDOW_AUTOSIZE);
    cv::imshow(WINDOW_NAME, image);
    trackbar();

    cv::waitKey(0);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int numberOfCircles = detectCircle(blurredImage);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    long long int duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    //SQLcreateRecord("circles", argv[2], duration, numberOfCircles, db);

    std::cout << std::endl << "Detected circles: " << numberOfCircles << std::endl;

    cv::imshow(WINDOW_NAME, blurredImage);
    cv::waitKey(0);

    cv::Mat basicImage = cv::imread(argv[3], cv::IMREAD_GRAYSCALE);
    cv::imshow(WINDOW_NAME, basicImage);
    cv::waitKey(0);

    cv::Mat patternImage = createLightPattern(basicImage);
    cv::imshow(WINDOW_NAME, patternImage);
    cv::waitKey(0);

    cv::Mat removedImage = removeLightWithDifference(basicImage, patternImage);
    cv::imshow(WINDOW_NAME, removedImage);
    cv::waitKey(0);

    cv::Mat binarizedImage = binarizeImage(basicImage);
    cv::imshow(WINDOW_NAME, removedImage);
    cv::waitKey(0);

    cv::Mat connectedImage = connectComponentsWithStats(binarizedImage);
    cv::imshow(WINDOW_NAME, connectedImage);
    cv::waitKey(0);

    cv::Mat originalImage = cv::imread(argv[4], cv::IMREAD_COLOR);
    cv::imshow("Original image", originalImage);
    cv::moveWindow("Original image", 400, 50);

    cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);
    cv::Mat drawHistogram = histogram(originalImage);
    cv::imshow("Histogram", drawHistogram);
    cv::moveWindow("Histogram", 0, 50);
    cv::waitKey(0);

    cv::Mat normalizeImage = normalizeColoring(originalImage);
    cv::imshow("Normalized", normalizeImage);
    drawHistogram = histogram(normalizeImage);
    cv::imshow("HistogramNormalized", drawHistogram);
    cv::waitKey(0);

    cv::Mat sharpenImage = sharpen(normalizeImage);
    cv::imshow("SharpenImage", sharpenImage);
    cv::waitKey(0);

	cv::Mat akazeFeaturePts = detectFeaturePointsAKAZE(normalizeImage);
	cv::imshow("FeaturePoints", akazeFeaturePts);
	cv::waitKey(0);

    sqlite3_close(db);

    return 0;
}

void gaussian(int, void *)
{
    cv::GaussianBlur(image, blurredImage, cv::Size(2 * sliderGaussian + 1, 2 * sliderGaussian + 1), sliderGaussian);
    imshow(WINDOW_NAME, blurredImage);
}
void median(int, void *)
{
    cv::medianBlur(image, blurredImage, 2 * sliderMedian + 1);
    imshow(WINDOW_NAME, blurredImage);
}

void trackbar()
{
    cv::createTrackbar("Gaussian Blur", WINDOW_NAME, &sliderGaussian, 25, gaussian);
    gaussian(1, nullptr);
    cv::createTrackbar("Median Blur", WINDOW_NAME, &sliderMedian, 25, median);
    median(1, nullptr);
}
