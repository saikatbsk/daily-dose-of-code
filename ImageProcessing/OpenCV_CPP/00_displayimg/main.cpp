/* Simple highgui demo program to open and display an image file */
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    int k;

    Mat src;                    /* Mat is a multidimensional data
                                   structure to store complex image
                                   matrices */
    src = imread("yoda.jpg");   /* read the image */

    /* now create a window and display the image we have just read */
    namedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    imshow("Source Image", src);

    /* we need to display the window until some key is pressed */
    while(k != 27)              /* we choose the ESC key */
        k = waitKey(1);         /* waitKey is essential because the
                                   processor needs some time to precess
                                   the image */

    src.release();              /* release the allocated memory */

    return 0;
}
