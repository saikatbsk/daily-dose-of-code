#include <iostream>

void permuteStr(std::string str, int l, int r) {
    int i;

    if(l == r)
        std::cout << str << std::endl;
    else {
        for(i=l ; i<=r ; i++) {
            std::swap((str.at(l)), (str.at(i)));
            permuteStr(str, l+1, r);
            std::swap((str.at(l)), (str.at(i)));
        }
    }
}

int main() {
    std::string X = "GEEK";

    int len = X.length();

    permuteStr(X, 0, len-1);

    return 0;
}
