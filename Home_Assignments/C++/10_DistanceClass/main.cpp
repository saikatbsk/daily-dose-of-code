/* ==================================================================
 * Assignment 11
 * ------------------------------------------------------------------
 * A program to implement the Distance class, and derive DistKMS from
 * the Distance class.
 * ==================================================================
 */

#include <iostream>

using namespace std;

class Distance {
protected:
    int distance;
public:
    void setDistance(int val) {
        distance = val;
    }
    virtual float travelTime() {
        return distance / float(60);
    }
};

class DistKMS : public Distance {
public:
    float travelTime() {
        return distance / float(100);
    }
};

int main() {
    int distance;

    Distance *d;
    DistKMS  dk;

    cout << "Distance? ";
    cin >> distance;

    dk.setDistance(distance);
    d = &dk;

    cout << "Travel time= " << d->travelTime() << " Hour.\n";

    return 0;
}
