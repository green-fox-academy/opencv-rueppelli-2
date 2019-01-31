#include "detect_circle.h"

cv::Mat detectCircle(cv::Mat image)
{
    if(!image.empty()) {

        cv::Mat gray;
        cvtColor(image, gray, cv::COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, cv::Size(5, 5), 0, 0);

        std::vector<cv::Vec3f> circles;
        HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows/6, 100, 30, 0, 0);

        for(size_t i = 0; i < circles.size(); i++)
        {
            cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int r = cvRound(circles[i][2]);
            circle( image, center, 7, cv::Scalar(255,0,255), -1, 4, 0);
            circle( image, center, r, cv::Scalar(0,255,0), 10, 4, 0);
        }
    }

    return image;
}
