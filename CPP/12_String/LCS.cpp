/* Longest Common Substring and Longest Common Subsequence */

#include <iostream>

int LCSubSeq(std::string X, std::string Y, int m, int n) {
    int LCSuff[m+1][n+1];

    if(m == 0 || n == 0)
        return 0;

    for(int i=0 ; i<=m ; i++) {
        for(int j=0 ; j<=n ; j++) {
            if(i==0 | j== 0)
                LCSuff[i][j] = 0;
            else if(X[i-1] == Y[j-1]) {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
            }
            else {
                LCSuff[i][j] = std::max(LCSuff[i-1][j], LCSuff[i][j-1]);
            }
        }
    }

    return LCSuff[m][n];
}

int LCSubStr(std::string X, std::string Y, int m, int n) {
    int LCSuff[m+1][n+1];
    int result = 0;

    if(m == 0 || n == 0)
        return 0;

    for(int i=0 ; i<=m ; i++) {
        for(int j=0 ; j<=n ; j++) {
            if(i==0 || j==0)
                LCSuff[i][j] = 0;
            else if(X[i-1] == Y[j-1]) {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = std::max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }

    return result;
}

int main() {
    std::string X = "GeeksforGeeks";
    std::string Y = "Geeks";

    int m = X.length();
    int n = Y.length();

    std::cout << LCSubStr(X, Y, m, n) << std::endl;

    return 0;
}
