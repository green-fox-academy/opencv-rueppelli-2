#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
#include "initial.h"
#include "sqlite_functions.h"
#include "detect_circle.h"

#define NAME "Computer Vision"
#define IMAGEPATH

cv::Mat image;
cv::Mat output;
sqlite3* db;

int sliderMax = 15;
int kernelSize = 1;

static void onTrackbar(int, void *);
static void onTrackbar2(int, void *);

int main(int argc, char** argv) {
    sqlite3_open("../files/opencv-2.db", &db);

    std::string imagePath("../img/balls12.jpg");
    image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if(argc > 1) {
        imagePath = argv[1];
    }

    if(image.empty()) {
        std::cout << "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }

    namedWindow(NAME, cv::WND_PROP_FULLSCREEN);
    cv::createTrackbar("Gaussian Blur", NAME, &kernelSize, sliderMax, onTrackbar);
    cv::createTrackbar("Median Blur", NAME, &kernelSize, sliderMax, onTrackbar2);

    cv::waitKey(0);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    cv::Mat circles = detectCircle(image);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    long long int duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    int circlessss = 6;

    SQLcreateRecord("circles", imagePath, duration, circlessss, db);

    std::cout << duration;

    cv::imshow(NAME, circles);
    cv::waitKey(0);

    sqlite3_close(db);

    return 0;
}

static void onTrackbar(int, void *)
{
    cv::GaussianBlur(image, output, cv::Size(2*kernelSize+1, 2*kernelSize+1), 0,0);
    imshow(NAME, output);
}
static void onTrackbar2(int, void *)
{
    cv::medianBlur(image, output, 2*kernelSize + 1);
    imshow(NAME, output);
}