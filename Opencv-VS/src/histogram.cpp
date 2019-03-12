#include "histogram.h"


cv::Mat histogram(cv::Mat image)
{
    std::vector<cv::Mat> bgr_planes;
    split(image, bgr_planes);

    int histSize = 256;
    float range[] = {0, 256} ;
    const float* histRange = {range};
    bool uniform = true;
    bool accumulate = false;

    cv::Mat b_hist, g_hist, r_hist;

    calcHist(&bgr_planes[0], 1, nullptr, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, nullptr, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, nullptr, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);

    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0,0,0));

    normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    for(int i = 1; i < histSize; i++){
        line(histImage, cv::Point(bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1))),
              cv::Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
              cv::Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, cv::Point(bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1))),
              cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
              cv::Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, cv::Point(bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1))),
              cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
              cv::Scalar(0, 0, 255), 2, 8, 0);
    }
    return histImage;
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
