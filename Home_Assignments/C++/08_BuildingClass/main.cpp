/* ==================================================================
 * Assignment 09
 * ------------------------------------------------------------------
 * A program  to implement  the building class,  and derive house and
 * office classes from the vehicle class.
 * ==================================================================
 */

#include <iostream>
#include <string.h>

using namespace std;

class Building {
protected:
    int floors;
    int rooms;
    int totalArea;
public:
    void setValues(int Floors, int Rooms, int TotalArea) {
        floors = Floors;
        rooms  = Rooms;
        totalArea = TotalArea;
    }
    int getTotalArea() {
        return totalArea;
    }
};

class House : public Building {
    int bedRooms;
    int bathRooms;
public:
    void setValues(int Floors, int Rooms, int TotalArea, int BedRooms, int BathRooms) {
        floors = Floors;
        rooms  = Rooms;
        totalArea = TotalArea;
        bedRooms  = BedRooms;
        bathRooms = BathRooms;
    }
};

class Office : public Building {
    int chairs;
    int tables;
    int telephones;
public:
    void setValues(int Floors, int Rooms, int TotalArea, int Chairs, int Tables, int Telephones) {
        floors = Floors;
        rooms  = Rooms;
        totalArea  = TotalArea;
        chairs     = Chairs;
        tables     = Tables;
        telephones = Telephones;
    }
};

void swap(int * x, int * y) {
    int tmp;

    tmp = *x;
    *x  = *y;
    *y  = tmp;
}

void sort(int data[], int ids[], int length) {
    int i, j;
    int l = length;

    for(i = 0 ; i < length ; i++) {
        for(j = 0 ; j < l ; j++ ) {
            if(data[j - 1] > data[j]) {
                swap(&data[j - 1], &data[j]);
                swap(&ids[j - 1], &ids[j]);
            }
        }
        l -= 1;
    }
}

int main() {
    Building b;
    House    h;
    Office   o;

    b.setValues(5, 30, 2000);
    h.setValues(3, 18, 1200, 12, 6);
    o.setValues(5, 30, 2400, 128, 32, 34);

    char labels[3][9];
    strcpy(labels[0], "Building");
    strcpy(labels[1], "House");
    strcpy(labels[2], "Office");

    int ids[3] = {0, 1, 2};
    int areas[3] = {b.getTotalArea(), h.getTotalArea(), o.getTotalArea()};

    sort(areas, ids, 3);

    for(int i = 0 ; i < 3 ; i++) {
        cout << labels[ids[i]] << " has area of " << areas[i] << " Square Feet.\n";
    }
    cout << endl;

    cout << "Smallest one is: " << labels[ids[0]] << " with area= " << areas[0] << " Square Feet.\n";

    return 0;
}
