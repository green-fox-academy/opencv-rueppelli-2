#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "initial.h"
#include "sqlite_functions.h"

#define NAME "Computer Vision"

int main(int argc, char** argv) {

    std::cout << initialFunction(3, 5) << std::endl;

    cv::String imagePath( "../img/balls12.jpg" );
    if( argc > 1)
    {
        imagePath = argv[1];
    }
    cv::Mat image;
    image = cv::imread( imagePath, cv::IMREAD_COLOR );
    if( image.empty() )
    {
        std::cout <<  "Sorry baby, I can't find the image." << std::endl ;
        return -1;
    }
    namedWindow( NAME, cv::WND_PROP_FULLSCREEN );
    imshow( NAME, image );
    cv::waitKey(0);
    return 0;

}
