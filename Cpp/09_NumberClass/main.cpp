/* ==================================================================
 * A program  to implement  the Number class, and derive OctalNum and
 * HexNum from Number class.
 * ==================================================================
 */

#include <iostream>

using namespace std;

class Number {
protected:
    int decimalValue;
public:
    void setNum(int num) {
        decimalValue = num;
    }
    virtual void displayNum() = 0;
};

class OctalNum : public Number {
public:
    void displayNum() {
        cout << oct << decimalValue;
    }
};

class HexNum : public Number {
public:
    void displayNum() {
        cout << hex << decimalValue;
    }
};

int main() {
    int num;

    Number   *number;
    OctalNum octalNum;
    HexNum   hexNum;

    cout << "Give me a number: ";
    cin >> num;

    octalNum.setNum(num);
    hexNum.setNum(num);

    number = &octalNum;
    cout << "Octal value= "; number->displayNum(); cout << endl;

    number = &hexNum;
    cout << "HexaDecimal value= "; number->displayNum(); cout << endl;

    return 0;
}
