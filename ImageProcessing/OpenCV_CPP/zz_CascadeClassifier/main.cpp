#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String cascades[100] = {
    "classifiers/banana_classifier.xml",
    "classifiers/haarcascade_frontalface_default.xml",
    "classifiers/classifier_WallClock.xml",
    "classifiers/haarcascade_fullbody.xml",
    "classifiers/haarcascade_upperbody.xml"
};

String cascade_names[100] = {
    "Banana", "Face", "WallClock", "Human", "UpperBody"
};

Scalar color[100] = {
    Scalar(0, 255, 255),
    Scalar(255, 255, 0),
    Scalar(255, 0, 0),
    Scalar(0, 255, 0),
    Scalar(0, 0, 255)
};

int objcount[100];

void detectAndDisplay(Mat frame) {
    vector<Rect> objects;
    Mat frame_gray;

    namedWindow("Result - CascadeClassifier", CV_WINDOW_AUTOSIZE);

    /* Convert the image to Grayscale and equalize histogram */
    cvtColor(frame, frame_gray, CV_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    cout << "Detected objects: ";

    /* Detect objects */
    for(int i = 0 ; i < 5 ; i++) {
        CascadeClassifier cascade;
        cascade.load(cascades[i]);
        cascade.detectMultiScale(frame_gray, objects, 1.1, 2, 0, Size(80, 80));

        /* Draw rectangles around detected objects */
        for(size_t j = 0 ; j < objects.size() ; j++) {
            Point pt1 = Point(objects[j].x, objects[j].y);
            Point pt2 = Point(objects[j].x + objects[j].width, objects[j].y + objects[j].height);

            rectangle(frame, pt1, pt2, color[i], 2, 8, 0);
            putText(frame, cascade_names[i], pt1, FONT_HERSHEY_SIMPLEX, 0.8, color[i], 1, CV_AA);
        }

        objcount[i] = objects.size();
        if(objcount[i] > 0)
            cout << cascade_names[i] << "(" << objcount[i] << ") ";
    }

    cout << endl;

    imshow("Result - CascadeClassifier", frame);
}

int main(int argc, char * argv[]) {
    int i, k;

    Mat src;

    if(argc < 2) {
        cerr << "---> Insufficient number of arguments!\n";
        cout << "Usage: a.out [image_file]\n";
        return -1;
    }

    /* Load input image */
    if((src = imread(argv[1])).empty()) {
        cerr << "---> Error loading image!\n";
        return -1;
    }

    /* Detect objects and display the image */
    detectAndDisplay(src);

    while((k = waitKey(1)) != 27) {}

    return 0;
}
