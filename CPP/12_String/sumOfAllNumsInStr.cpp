#include <iostream>

using namespace std;

int sumOfAllNumsInString(string str) {
    string tmp = "";
    int sum = 0;

    for(char ch : str) {
        if(isdigit(ch)) {
            tmp += ch;
        }
        else {
            sum += atoi(tmp.c_str());
            tmp = "";
        }
    }

    return sum + atoi(tmp.c_str());
}

int main() {
    string str = "1abc2x30yz67";

    cout << sumOfAllNumsInString(str);

    return 0;
}
