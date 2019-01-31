#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "initial.h"
#include "sqlite_functions.h"
#include "detect_circle.h"

#define NAME "Computer Vision"

cv::Mat image;
cv::Mat output;

int sliderMax = 15;
int kernelSize = 1;

static void onTrackbar(int, void *);
static void onTrackbar2(int, void *);

int main(int argc, char** argv) {

    cv::String imagePath("../img/balls12.jpg");
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

    cv::Mat circles = detectCircle(image);

    cv::imshow(NAME, circles);
    cv::waitKey(0);

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