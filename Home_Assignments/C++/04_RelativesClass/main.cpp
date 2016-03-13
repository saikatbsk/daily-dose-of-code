/* ==================================================================
 * Assignment 05
 * ------------------------------------------------------------------
 * A program to implement the relatives class.
 * ==================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXNAMELEN 32
#define MAXADDRLEN 128

using namespace std;

class Relative {
    char * name;         //-- Should be re-written using String class
    char * address;      //-- Should be re-written using String class
public:
    Relative() {
        name = (char *)malloc(sizeof(char) * MAXNAMELEN);
        address = (char *)malloc(sizeof(char) * MAXADDRLEN);
    }
    void setDetails(char * Name, char * Address) {
        strcpy(name, Name);
        strcpy(address, Address);
    }
    void getDetails() {
        cout << "Name: " << name << "\n"
             << "Address: " << address << "\n";
    }
};

int main() {
    char * name;
    char * addr;

    Relative person;

    name = (char *)malloc(sizeof(char) * MAXNAMELEN);
    addr = (char *)malloc(sizeof(char) * MAXADDRLEN);

    cout << "Enter details..\n";

    cout << "Name: ";
    cin >> name;

    cout << "Address: ";
    cin >> addr;

    person.setDetails(name, addr);
    person.getDetails();

    return 0;
}
