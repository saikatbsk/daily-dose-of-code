#include <opencv2/opencv.hpp>
#include <iostream>
#define MAXVAL 255

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
    int i, j, k;
    int cols, rows;
    int thresh;                     //-- Applied threshold
    float nthresh;                  //-- Normalized threshold

    if(argc < 2) {
        cerr << ">>> Error! Input image not specified!" << endl;
        cout << "Usage: a.out [input_image.jpg]" << endl;
        return -1;
    }

    Mat src;                        //-- Source image matrix
    Mat gray;                       //-- Grayscale image matrix
    Mat bin;                        //-- Binary image matrix

    /* Load an image first */
    src  = imread(argv[1]);
    cols = src.cols;
    rows = src.rows;

    /* Get normalized threshold and calculate threshold value to be applied */
    cout << "Enter threshold (value between 0 to 1): " << endl;
    cin >> nthresh;
    thresh = nthresh * MAXVAL;

    /* Create windows to preview the images */
    namedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    namedWindow("Binary Image", CV_WINDOW_AUTOSIZE);

    /* Convert the BGR image to Grayscale */
    cvtColor(src, gray, CV_BGR2GRAY);

    /* Initialize the matrix with zeros */
    bin = Mat::zeros(src.size(), CV_8UC1);

    /*
     * For each pixel, if pixel intensity is greater than 1 then
     * corresponding pixel intensity in the binary image becomes 1
     * else it is 0
     */
    for(i = 0 ; i < rows ; i++) {
        for(j = 0 ; j < cols ; j++) {
            if(gray.at<uchar>(i, j) > thresh)
                bin.at<uchar>(i, j) = MAXVAL;
            else
                bin.at<uchar>(i, j) = 0;
        }
    }

    /* Show the final result */
    imshow("Source Image", src);
    imshow("Binary Image", bin);

    /* waitKey is necessary as image processing requires time */
    while((k = waitKey(100)) != 27 /* ESCAPE */) {}

    /* Release the matrices and destroy all windows */
    src.release();
    gray.release();
    bin.release();
    destroyAllWindows();

    return 0;
}
