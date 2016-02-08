#ifndef _HELPER_HPP_
#define _HELPER_HPP_

#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
void putLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);

#endif
