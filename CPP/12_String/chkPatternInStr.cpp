#include <iostream>

using namespace std;

bool chkPatternInString(string str, string pattern) {
    int len = pattern.length();

    if(len > str.length())
        return false;

    for(int i=0 ; i<len-1 ; i++) {
        char x = pattern[i];
        char y = pattern[i+1];

        size_t first = str.find_first_of(y);
        size_t last  = str.find_last_of(x);

        if(first < last || first == string::npos || last == string::npos)
            return false;
    }

    return true;
}

int main() {
    string str = "engineer";
    string pattern = "er";

    cout << boolalpha << chkPatternInString(str, pattern);

    return 0;
}
