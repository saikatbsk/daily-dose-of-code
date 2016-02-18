#include "helper.hpp"

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
    Mat src = imread("img/shapes2.png");
    if(src.empty())
        return -1;

    //-- Convert to grayscale
    Mat gray;
    cvtColor(src, gray, CV_BGR2GRAY);

    //-- Use Canny to create bw image
    Mat bw;
    Canny(gray, bw, 0, 50, 5 /* aperture size for Sobel() */);

    //-- Find contours
    vector<vector<Point> > contours;
    findContours(bw, contours,
                 CV_RETR_EXTERNAL /* extreme outer contours */,
                 CV_CHAIN_APPROX_SIMPLE /* compresses horizontal, vertical, and diagonal segments
                                         * and leaves only their end points */);

    vector<Point> approx;
    Mat dst = src.clone();

    for(int i = 0 ; i < contours.size() ; i++) {
        //-- Approximate contour with accuracy proportional to the contour perimeter
        approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true) * 0.02, true);

        //-- Skip small or non-convex objects
        if(fabs(contourArea(contours[i])) < 100 || !isContourConvex(approx))
            continue;

        if(approx.size() == 3)
            putLabel(dst, "TRIANGLE", contours[i]);     //-- Triangles
        else if(approx.size() >= 4 && approx.size() <= 6) {
            //-- Number of vertices of polygonal curve
            int vertices = approx.size();

            //-- Get the cosines of all corners
            vector<double> cos;
            for(int j = 2 ; j < vertices + 1 ; j++)
                cos.push_back(angle(approx[j % vertices], approx[j - 2], approx[j - 1]));

            //-- Sort cosine values in ascending order
            sort(cos.begin(), cos.end());

            //-- Get the lowest and the highest cosine
            double mincos = cos.front();
            double maxcos = cos.back();

            //-- Use the degrees obtained above and the number of vertices to determine the shape of the contour
            if(vertices == 4 && mincos >= -0.1 && maxcos <= 0.3)
                putLabel(dst, "RECTANGLE", contours[i]);
            else if(vertices == 5 /* && mincos >= -0.34 && maxcos <= -0.27 */)
                putLabel(dst, "PENTAGON", contours[i]);
            else if(vertices == 6 && mincos >= -0.65 && maxcos <= -0.35)
                putLabel(dst, "HEXAGON", contours[i]);
        }
        else {
            //-- Detect and label circles
            double area = contourArea(contours[i]);
            Rect r = boundingRect(contours[i]);
            int radius = r.width / 2;

            if(abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.2)
                putLabel(dst, "CIRCLE", contours[i]);
        }
    }

    //imshow("Source Image", src);
    //Mat tmp;

    //pyrDown(dst, tmp, Size((src.cols + 1) / 2, (src.rows + 1) / 2), BORDER_DEFAULT);
    imshow("Destination Image", dst);
    waitKey(0);

    return 0;
}
