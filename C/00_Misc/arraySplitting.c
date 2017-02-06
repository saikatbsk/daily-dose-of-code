/* Problem: https://www.hackerrank.com/challenges/array-splitting */
#include <stdio.h>

int max(int x, int y) {
    return (x > y)? x:y;
}

int maxPts(int arr[], int start, int end) {
    int pts = 0;
    int s1, s2;

    if(end == start)
        return 0;

    s1 = s2 = 0;
    for(int i = start ; i <= end ; i++)
        s2 += arr[i];

    for(int i = start ; i <= end-1 ; i++) {
        s1 += arr[i];
        s2 -= arr[i];

        if(s1 == s2) {
            pts++;
            pts += max(maxPts(arr, start, i), maxPts(arr, i+1, end));
            break;
        }
    }

    return pts;
}

int main() {
    int T, N, A[16384], maxpts;
    fscanf(stdin, "%d", &T);

    for(int i = 0 ; i < T ; i++) {
        fscanf(stdin, "%d", &N);

        for(int j = 0 ; j < N ; j++) {
            fscanf(stdin, "%d", &A[j]);
        }

        maxpts = maxPts(A, 0, N-1);
        printf("%d\n", maxpts);
    }

    return 0;
}
