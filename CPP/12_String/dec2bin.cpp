#include <iostream>

using namespace std;

//-- Decimal to binary 8 bit representation
string dec2bin(long long n) {
    string bin = "";

    for(int i=sizeof(long long)-1 ; i>=0 ; i--) {
        bool val = n & (1<<i);
        bin += to_string(val);
    }

    return bin;
}

int main() {
    long long dec;

    for(dec=0 ; dec<=9 ; dec++)
        cout << dec << " = " << dec2bin(dec) << endl;

    return 0;
}
