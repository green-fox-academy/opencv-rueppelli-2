#include "detect_circle.h"

int detectCircle(cv::Mat &image)
{
        cv::Mat imageMask = cv::Mat::zeros(image.size(), image.type());
        cv::Mat imageDestination = cv::Mat::ones(image.size(), image.type());

        cv::Mat image2 = image.clone();

        //GaussianBlur(image, image, cv::Size(5, 5), 0, 0);

        std::vector<cv::Vec3f> circles;
        HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1, image.rows/4, 50, 130, 0, 0);
        int numberOfCircles = 0;
        cvtColor(image, image, cv::COLOR_GRAY2BGR);

        for (size_t i = 0; i < circles.size(); i++) {


            cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int r = cvRound(circles[i][2]);
            circle(image, center, 7, cv::Scalar(255,0,255), -1, 4, 0);
            circle(image, center, r, cv::Scalar(0,255,0), 10, 4, 0);

            std::string areaString = std::to_string(r * r);
            int centerX = cvRound(circles[i][0]);
            int centerY = cvRound(circles[i][1]);

            cv::circle(imageMask, cv::Point(centerX, centerY), r, cv::Scalar(255, 255, 255), -1, 8, 0);
            image2.copyTo(imageDestination, imageMask);

            cv::putText(image, "Area:", cv::Point(centerX - r/4,centerY - r/2), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);
            cv::putText(image, areaString, cv::Point(centerX - r/3,centerY - r/4), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

            std::string xString = std::to_string(centerX);
            cv::putText(image, "X: " + xString, cv::Point(centerX - r/2 - r/4, centerY + r/3), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

            std::string yString = std::to_string(centerY);
            cv::putText(image, "Y: " + yString, cv::Point(centerX + r/4, centerY + r/3), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

            numberOfCircles++;
        }
        cv::imshow("masked", imageDestination);
        cv::waitKey(0);
        return numberOfCircles;
}
