/* ==================================================================
 * Assignment 07
 * ------------------------------------------------------------------
 * A program to implement the relatives class.
 * ==================================================================
 */

#include <iostream>

using namespace std;

class Box {
    double length;
    double width;
    double height;
public:
    Box(double l, double w, double h);
    double vol();
};

Box::Box(double l, double w, double h) {
    length = l;
    width  = w;
    height = h;
}

double Box::vol() {
    return length * width * height;
}

int main() {
    Box b(34.8, 23.8, 29.9);

    cout << "Volume: " << b.vol() << " Cubic Units.\n";

    return 0;
}
