#include <iostream>

using namespace std;

namespace mine {
    int test(int input) {
        if(input % 2 == 0)
            return 1;
        else
            return 0;
    }
}

int main() {
    int val;

    cout << "Enter a value: ";
    cin >> val;

    if(mine::test(val))
        cout << "The value entered is Even.\n";
    else
        cout << "The value entered is Odd.\n";

    return 0;
}
