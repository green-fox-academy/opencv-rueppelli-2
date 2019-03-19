#include "img_detection.h"

int detectCircle(cv::Mat &image)
{
    cv::Mat imageMask = cv::Mat::zeros(image.size(), image.type());
    cv::Mat imageDestination = cv::Mat::ones(image.size(), image.type());

    cv::Mat image2 = image.clone();

    GaussianBlur(image, image, cv::Size(5, 5), 0, 0);

    std::vector<cv::Vec3f> circles;
    HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1, image.rows/4, 50, 130, 0, 0);
    int numberOfCircles = 0;
    cvtColor(image, image, cv::COLOR_GRAY2BGR);

    for (size_t i = 0; i < circles.size(); i++) {
        cv::Point circleCenter(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int circleRadius = cvRound(circles[i][2]);
        int circleAreaI = (int)(circleRadius * circleRadius);
        std::string circleAreaS = std::to_string(circleAreaI);
        int circleCenterX = cvRound(circles[i][0]);
        int circleCenterY = cvRound(circles[i][1]);

        circle(image, circleCenter, 7, cv::Scalar(255,0,255), -1, 4, 0);
        circle(image, circleCenter, circleRadius, cv::Scalar(0,255,0), 10, 4, 0);

        cv::circle(imageMask, cv::Point(circleCenterX, circleCenterY), circleRadius, cv::Scalar(255, 255, 255), -1, 8, 0);
        image2.copyTo(imageDestination, imageMask);

        cv::putText(image, "Area:", cv::Point(circleCenterX - circleRadius /4, circleCenterY - circleRadius /2), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);
        cv::putText(image, circleAreaS, cv::Point(circleCenterX - circleRadius /3, circleCenterY - circleRadius /4), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

        std::string xString = std::to_string(circleCenterX);
        cv::putText(image, "X: " + xString, cv::Point(circleCenterX - circleRadius /2 - circleRadius /4, circleCenterY + circleRadius /3), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

        std::string yString = std::to_string(circleCenterY);
        cv::putText(image, "Y: " + yString, cv::Point(circleCenterX + circleRadius /4, circleCenterY + circleRadius /3), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,255), 2, 8, false);

        numberOfCircles++;
    }
    cv::imshow("Masked", imageDestination);
    return numberOfCircles;
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
		for (int i = 1; i < nLabels; i++) {
			if (stats.at<int>(i, cv::CC_STAT_AREA) == sortedAreas[j]) {
				std::string biggest = std::to_string(j + 1);
				cv::putText(newImage, biggest, cv::Point(centroids.at<cv::Point2d>(i)),
					cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1, 8, false);
			}
		}
	}
	return newImage;
}

void detectFeaturePointsAKAZE()
{
	//Implement a method which is able to detect feature points using the AKAZE detector. 
	//Write out how many feature points were detected by this method.
}

void detectFeaturePointsFFD()
{
	//Implement a method which is able to detect feature points using the Fast Feature Detector. 
	//Write out how many feature points were detected by this metho
}
