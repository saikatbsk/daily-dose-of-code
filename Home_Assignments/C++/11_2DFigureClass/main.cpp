/* ==================================================================
 * Assignment 12
 * ------------------------------------------------------------------
 * A program to implement the 2DFigure class.
 * ==================================================================
 */

#include <iostream>

using namespace std;

class twoDFigure {
protected:
    double dim1;
    double dim2;
public:
    virtual double calculateArea() = 0;
};

class Rectangle : public twoDFigure {
public:
    Rectangle() {
        dim1 = 0;
        dim2 = 0;
    }
    Rectangle(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }
    double calculateArea() {
        return dim1 * dim2;
    }
};

class Triangle : public twoDFigure {
public:
    Triangle() {
        dim1 = 0;
        dim2 = 0;
    }
    Triangle(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }
    double calculateArea() {
        return (dim1 * dim2) / 2;
    }
};

int main() {
    twoDFigure *f;
    Rectangle r(30, 40);
    Triangle  t(40, 40);

    f = &r;
    cout << "Area of Rectangle= " << f->calculateArea() << "\n";

    f = &t;
    cout << "Area of Triangle= " << f->calculateArea() << "\n";

    return 0;
}
