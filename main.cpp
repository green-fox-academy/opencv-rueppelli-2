#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "sqlite_functions.h"
#include "detect_circle.h"
#include "sort_functions.h"
#include "remove_background.h"

#define NAME "Computer Vision"

void gaussian(int, void *);
void median(int, void *);
void trackbar();

cv::Mat image;
cv::Mat blurredImage;
int sliderGaussian = 0;
int sliderMedian = 0;

int main() {
    srand(time(nullptr));

    sqlite3* db;
    int rc = sqlite3_open("../files/opencv-2.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_open("../files/opencv-2.db", &db);

    std::string imagePath("../img/balls11.jpg");

    image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);

    if(!image.data) {
        std::cout << "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }

    namedWindow(NAME, cv::WINDOW_AUTOSIZE);
    cv::imshow(NAME, image);
    trackbar();

    cv::waitKey(0);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int numberOfCircles = detectCircle(blurredImage);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    long long int duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    // SQLcreateRecord("circles", imagePath, duration, numberOfCircles, db);
    std::cout << std::endl << "Detected circles: " << numberOfCircles << std::endl;

    cv::imshow(NAME, blurredImage);
    cv::waitKey(0);

    cv::Mat basicImage = cv::imread("../img/shapes.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat patternImage = createLightPattern(basicImage);
    cv::Mat removedImage = removeLightWithDifference(basicImage, patternImage);
    cv::Mat binarizedImage = binarizeImage(removedImage);
    cv::Mat connectedImage = connectComponentsWithStats(binarizedImage);
    cv::imshow(NAME, connectedImage);
    cv::waitKey(0);

    sqlite3_close(db);

    return 0;
}

void gaussian(int, void *)
{
    cv::GaussianBlur(image, blurredImage, cv::Size(2 * sliderGaussian + 1, 2 * sliderGaussian + 1), sliderGaussian);
    imshow(NAME, blurredImage);
}
void median(int, void *)
{
    cv::medianBlur(image, blurredImage, 2 * sliderMedian + 1);
    imshow(NAME, blurredImage);
}

void trackbar()
{
    cv::createTrackbar("Gaussian Blur", NAME, &sliderGaussian, 25, gaussian);
    gaussian(1, nullptr);
    cv::createTrackbar("Median Blur", NAME, &sliderMedian, 25, median);
    median(1, nullptr);
}
