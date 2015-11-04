#include <iostream>

using namespace std;

extern "C" int getValue();

int main() {
    cout << getValue() << endl;

    return 0;
}
