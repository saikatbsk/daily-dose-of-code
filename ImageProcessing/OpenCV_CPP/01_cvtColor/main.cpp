#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    int k;

    /*
     * Open and capture from a video capture device.
     * Index 0 indicates the default capture device.
     */
    VideoCapture cap(0);

    Mat src;                        //-- Source matrix
    Mat gray;                       //-- Destination matrix (Grayscale)
    Mat hsv;                        //-- Destination matrix (HSV)

    /* Create two windows */
    namedWindow("Source", CV_WINDOW_AUTOSIZE);
    namedWindow("Converted (Grayscale)", CV_WINDOW_AUTOSIZE);
    namedWindow("Converted (HSV)", CV_WINDOW_AUTOSIZE);

    while(k != 27) {
        /* Generate the source matrix */
        cap >> src;

        /* Convert to Grayscale */
        cvtColor(src, gray, CV_BGR2GRAY);
        cvtColor(src, hsv, CV_BGR2HSV);

        /* Show the results */
        imshow("Source", src);
        imshow("Converted (Grayscale)", gray);
        imshow("Converted (HSV)", hsv);

        /* waitKey is necessary as processing requires some time */
        k = waitKey(1);
    }

    /* Release the matrices and destroy all windows */
    src.release();
    gray.release();
    hsv.release();
    destroyAllWindows();

    return 0;
}
