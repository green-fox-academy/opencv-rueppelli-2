#include "img_filtering.h"
#include "sort_functions.h"

cv::Mat removeLightWithDifference(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = pattern - image;
    return newImage;
}

cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern)
{
    cv::Mat newImage = 255 * (1 - (pattern / image));
    return newImage;
}

cv::Mat createLightPattern(cv::Mat image)
{
    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(image.cols / 3, image.rows / 3));

    return pattern;
}

cv::Mat binarizeImage(cv::Mat image)
{
    cv::Mat newImage;
    cv::threshold(image, newImage, 0, 255, cv::THRESH_OTSU);

    int allPixels = newImage.rows * newImage.cols;
    int whitePixels = cv::countNonZero(newImage);
    int blackPixels = allPixels - whitePixels;

	return whitePixels < blackPixels ? newImage : ~newImage;
}

cv::Mat sharpen(cv::Mat image)
{
    cv::Mat result;
    cv::Mat kernel = (cv::Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cv::filter2D(image, result, image.depth(), kernel);

    return result;
}

cv::Mat normalizeColoring(cv::Mat img)
{
	cv::Mat result;
	cv::Mat ycrcb;
	cvtColor(img, ycrcb, cv::COLOR_BGR2YCrCb);

	std::vector<cv::Mat> channels;
	split(ycrcb, channels);
	equalizeHist(channels[0], channels[0]);
	merge(channels, ycrcb);
	cvtColor(ycrcb, result, cv::COLOR_YCrCb2BGR);

	return result;
}
