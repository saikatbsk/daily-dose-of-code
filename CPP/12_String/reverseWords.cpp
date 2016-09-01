#include <iostream>

using namespace std;

string reverseStr(string str) {
    int len = str.length();
    string tmp = "";

    for(int i=len-1 ; i>=0 ; i--) {
        tmp += str.at(i);
    }

    return tmp;
}

string toSmallCaps(string str) {
    int len = str.length();
    int i = 0;
    string tmp;

    while(i < len) {
        if(str.at(i) >= 65 && str.at(i) <= 90) {
            //tmp += (char)((int)str.at(i) + 32);
            tmp += tolower(str.at(i));
        }
        else
            tmp += str.at(i);

        i++;
    }

    return tmp;
}

void reverseWordsInStr(string str) {
    string tmp = "";
    string strArr[100];
    string finalArr[100];
    int i = 0;
    int k = 0;
    int j = 0;

    //-- Remove blank spaces
    while(i < str.length()) {
        if(str.at(i) == ' ') {
            strArr[k] = tmp;
            k++;

            tmp = "";
        }
        else {
            tmp += str.at(i);
        }

        i++;
    }
    strArr[k] = tmp;

    for(i=0 ; i<=k ; i++) {
        if(strArr[i] != "") {
            finalArr[j] = strArr[i];
            j++;
        }
    }

    tmp = "";

    //-- Rest of it
    for(i=0 ; i<j ; i++) {
        finalArr[i] = reverseStr(toSmallCaps(finalArr[i]));
        finalArr[i].at(0) = toupper(finalArr[i].at(0));
        cout << finalArr[i] << " ";
    }
}

int main() {
    string inp = "my nAMe is john";

    reverseWordsInStr(inp);

    return 0;
}
