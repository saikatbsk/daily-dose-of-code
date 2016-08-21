#include <iostream>

int ifSubSeq(std::string X, std::string Y, int m, int n) {
    if(m == 0 || n == 0)
        return 0;

    int j = 0;

    for(int i=0 ; i<m && j<n ; i++) {
        if(Y[j] == X[i])
            j++;
    }

    return (j == n);
}

/* Bonus: if substring */
int ifSubStr(std::string X, std::string Y, int m, int n) {
    if(m == 0 || n == 0)
        return 0;

    int j = 0;

    for(int i=0 ; i<m && j<n ; i++) {
        if(Y[j] == X[i])
            j++;
        else if(j > 0 && Y[j] != X[i])
            return 0;
    }

    return (j == n);
}

int main() {
    std::string X = "GeeksforGeeks";
    std::string Y = "Geeks";

    int m = X.length();
    int n = Y.length();

    if(ifSubStr(X, Y, m, n)) std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    return 0;
}
