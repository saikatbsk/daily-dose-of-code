#include <iostream>
#include "05_proj.hpp"

using namespace std;
using namespace Boxes;

int main() {
    Box Box1;
    double volume = 0.0;

    Box1.length  = 6.7;
    Box1.breadth = 7.9;
    Box1.height  = 8.0;

    volume = Box1.length * Box1.breadth * Box1.height;
    cout << "Volume of Box1: " << volume << endl;

    return 0;
}
