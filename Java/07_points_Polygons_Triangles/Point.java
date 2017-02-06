import java.lang.Math;

class Point {
    double x;
    double y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double xval, double yval) {
        x = xval;
        y = yval;
    }

    double getDistanceFrom(Point pt) {
        return Math.sqrt(Math.pow((this.x - pt.x), 2) + Math.pow((this.y - pt.y), 2));
    }
}
