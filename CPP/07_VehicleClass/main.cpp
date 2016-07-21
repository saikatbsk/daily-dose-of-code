/* ==================================================================
 * A program to implement the vehicle class, and derive car and truck
 * classes from the vehicle class.
 * ==================================================================
 */

#include <iostream>

using namespace std;

class Vehicle {
protected:
    int numberOfWheels;
    int speedPerHour;
public:
    int speed() {
        return speedPerHour;
    }
    bool isFasterThan(int SpeedPerHour) {
        if(speedPerHour > SpeedPerHour)
            return true;
        else
            return false;
    }
};

class Car : public Vehicle {
    int numberOfPassengers;
public:
    void setValue(int NumberOfWheels, int SpeedPerHour, int NumberOfPassengers) {
        numberOfWheels = NumberOfWheels;
        speedPerHour   = SpeedPerHour;
        numberOfPassengers = NumberOfPassengers;
    }
    void display() {
        cout << "Number of wheels: " << numberOfWheels << "\n"
             << "Speed per hour  : " << speedPerHour << "\n"
             << "Number of Passengers: " << numberOfPassengers << "\n";
    }
};

class Truck : public Vehicle {
    int loadLimit;
public:
    void setValue(int NumberOfWheels, int SpeedPerHour, int LoadLimit) {
        numberOfWheels = NumberOfWheels;
        speedPerHour   = SpeedPerHour;
        loadLimit      = LoadLimit;
    }
    void display() {
        cout << "Number of wheels: " << numberOfWheels << "\n"
             << "Speed per hour  : " << speedPerHour << "\n"
             << "Load Limit      : " << loadLimit << "\n";
    }
};

int main() {
    Car car;
    Truck truck;

    car.setValue(4, 140, 6);
    cout << "Displaying values of car object..\n";
    car.display();

    cout << endl;

    truck.setValue(8, 120, 4000);
    cout << "Displaying values of truck object..\n";
    truck.display();

    cout << endl;
    cout << "Comparing speed.. ";
    if(car.isFasterThan(truck.speed()) == true)
        cout << "car is faster than truck.\n";
    else
        cout << "car is not faster than truck.\n";

    return 0;
}
