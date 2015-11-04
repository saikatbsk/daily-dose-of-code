#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//String cascadename = "classifiers/banana_classifier.xml";
String cascadename = "classifiers/haarcascade_frontalface_default.xml";
CascadeClassifier cascade;

void detectAndDisplay(Mat frame) {
    vector<Rect> objects;
    Mat frame_gray;

    namedWindow("Result - CascadeClassifier", CV_WINDOW_AUTOSIZE);

    cvtColor(frame, frame_gray, CV_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    //-- Detect objects
    cascade.detectMultiScale(frame_gray   /* Matrix of the type CV_8U */,
                             objects      /* Vector of rectangles */,
                             1.1          /* scaleFactor: how much the image size is reduced at each image scale */,
                             2            /* minNeighbors: how many neighbors each candidate rectangle should have */,
                             0,
                             Size(10, 10) /* Objects smaller than the size are ignored */
                            );

    for(size_t i = 0 ; i < objects.size() ; i++) {
        Point pt1 = Point(objects[i].x, objects[i].y);
        Point pt2 = Point(objects[i].x + objects[i].width, objects[i].y + objects[i].height);

        rectangle(frame, pt1, pt2, Scalar(255, 255, 0), 2, 8, 0);
    }

    imshow("Result - CascadeClassifier", frame);
}

int main(int argc, char * argv[]) {
    int k;

    Mat src;

    if(argc < 2) {
        cerr << "---> Insufficient number of arguments!\n";
        cout << "Usage: a.out [image_file]\n";
        return -1;
    }

    if((src = imread(argv[1])).empty()) {
        cerr << "---> Error loading image!\n";
        return -1;
    }

    if(!(cascade.load(cascadename))) {
        cerr << "---> Error loading cascade!\n";
        return -1;
    }

    detectAndDisplay(src);

    while((k = waitKey(1)) != 27) {}

    return 0;
}
