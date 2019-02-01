#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>

#include "initial.h"
#include "sqlite_functions.h"
#include "detect_circle.h"
#include "blur.h"

#define NAME "Computer Vision"

cv::Mat image;
cv::Mat gray;
cv::Mat blurredImage;

int sliderGaussian = 0;
int sliderMedian = 0;

sqlite3* db;

int main(int argc, char** argv) {

    sqlite3_open("../files/opencv-2.db", &db);

    std::string imagePath("../img/balls11.jpg");
    image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if(argc > 1) {
        imagePath = argv[1];
    }

    if(image.empty()) {
        std::cout << "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }

    namedWindow(NAME, cv::WINDOW_AUTOSIZE);
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::imshow(NAME, gray);
    trackbar();

    cv::waitKey(0);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    cv::Mat circles = detectCircle();
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    long long int duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    int circlessss = 6;

    SQLcreateRecord("circles", imagePath, duration, circlessss, db);

    cv::imshow(NAME, circles);
    cv::waitKey(0);

    sqlite3_close(db);

    return 0;
}
