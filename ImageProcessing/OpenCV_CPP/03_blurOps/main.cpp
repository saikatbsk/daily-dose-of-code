#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
    int k;

    Mat src;
    Mat dstG;
    Mat dstB;

    src = imread("rio.jpg");

    namedWindow("Input",        CV_WINDOW_AUTOSIZE);
    namedWindow("GaussianBlur", CV_WINDOW_AUTOSIZE);
    namedWindow("Blur",         CV_WINDOW_AUTOSIZE);

    imshow("Input", src);

    GaussianBlur(src, dstG, Size(3, 3), 0, 0);
    blur(src, dstB, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

    imshow("GaussianBlur", dstG);
    imshow("Blur", dstB);

    while((k = waitKey(1)) != 27) {}

    return 0;
}
