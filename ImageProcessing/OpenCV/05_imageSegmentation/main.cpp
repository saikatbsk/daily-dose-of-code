/*
 * This program demonstrates kmeans clustering
 * Status: WORKING
 */
#include <opencv2/opencv.hpp>
#include <sstream>
#define MAX_CLUSTERS 5
#define MAX_ATTEMPTS 3

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
    Mat src = imread(argv[1], 1 /* CV_LOAD_IMAGE_COLOR */);
    Mat tmp = src.clone();

    cvtColor(tmp, tmp, CV_BGR2Lab);
    blur(tmp, tmp, Size(15, 15));

    Mat dat(src.rows * src.cols, 3, CV_32F);

    for(int y = 0 ; y < src.rows ; y++)
        for(int x = 0 ; x < src.cols ; x++)
            for(int z = 0 ; z < 3 ; z++)
                dat.at<float>(y + x * src.rows, z) = tmp.at<Vec3b>(y, x)[z];

    tmp.release();

    Mat labels;
    Mat centers;

    kmeans(dat, MAX_CLUSTERS, labels,
            TermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 1000, 0.0001),
            MAX_ATTEMPTS, KMEANS_PP_CENTERS, centers);

    Mat clusters[MAX_CLUSTERS];

    for(int i = 0 ; i < MAX_CLUSTERS ; i++)
        clusters[i] = Mat::zeros(src.size(), src.type());

    for(int y = 0 ; y < src.rows ; y++)
        for(int x = 0 ; x < src.cols ; x++) {
            int clusterIdx;

            clusterIdx = labels.at<int>(y + x * src.rows, 0);

            for(int z = 0 ; z < 3 ; z++)
                clusters[clusterIdx].at<Vec3b>(y, x)[z] = centers.at<float>(clusterIdx, z);
        }

    pyrDown(src, tmp, Size((src.cols + 1) / 2, (src.rows + 1) / 2), BORDER_DEFAULT);
    imshow("Source Image", tmp);
    tmp.release();

    for(int i = 0 ; i < MAX_CLUSTERS ; i++) {
        Mat gray, bin;

        cvtColor(clusters[i], gray, CV_BGR2GRAY);
        threshold(gray, bin, 1, 255, CV_THRESH_BINARY);
        cvtColor(bin, bin, CV_GRAY2BGR);
        bitwise_and(src, bin, tmp);

        string title;
        stringstream s;

        s << "Extracted Objects #" << i;
        title = s.str();

        pyrDown(tmp, tmp, Size((src.cols + 1) / 2, (src.rows + 1) / 2), BORDER_DEFAULT);
        imshow(title, tmp);

        gray.release();
        bin.release();
        tmp.release();
    }

    waitKey(0);
    return 0;
}
