#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "sqlite_functions.h"
#include "blur.h"
#include "detect_circle.h"

#define NAME "Computer Vision"

cv::Mat image;
cv::Mat gray;
cv::Mat blurredImage;
int sliderGaussian = 0;
int sliderMedian = 0;

int main(int argc, char** argv) {

    sqlite3* db;
    int rc = sqlite3_open("../files/opencv-2.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(-1);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_open("../files/opencv-2.db", &db);

    std::string imagePath("../img/baldasdls11.jpg");
    image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if(argc > 1) {
        imagePath = argv[1];
    } else if(image.empty()) {
        std::cout << "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }

    namedWindow(NAME, cv::WINDOW_AUTOSIZE);
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::imshow(NAME, gray);
    trackbar();

    cv::waitKey(0);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int numberOfCircles = detectCircle(image);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    long long int duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    SQLcreateRecord("circles", imagePath, duration, numberOfCircles, db);
    std::cout << std::endl << "Detected circles: " << numberOfCircles << std::endl;

    cv::imshow(NAME, image);
    cv::waitKey(0);
    sqlite3_close(db);

    return 0;
}
