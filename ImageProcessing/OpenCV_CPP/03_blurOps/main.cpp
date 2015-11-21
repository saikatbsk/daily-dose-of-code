#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
    int k;

    /* Defining image matrices */
    Mat src;
    Mat dstG;
    Mat dstB;

    /* Read the source image */
    src = imread("rio.jpg");

    /* Create output windows */
    namedWindow("Input",        CV_WINDOW_AUTOSIZE);
    namedWindow("GaussianBlur", CV_WINDOW_AUTOSIZE);
    namedWindow("Blur",         CV_WINDOW_AUTOSIZE);

    /* Show the source image */
    imshow("Input", src);

    /* Apply blur operations */
    GaussianBlur(src, dstG, Size(3, 3), 0, 0);
    blur(src, dstB, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

    /* Show the output images */
    imshow("GaussianBlur", dstG);
    imshow("Blur", dstB);

    /* Wait while user hits the ESCAPE key */
    while((k = waitKey(1)) != 27) {}

    return 0;
}
