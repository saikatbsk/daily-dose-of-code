/*
 * Given a 2-D matrix with M rows and N columns, find the number of ways to reach cell with coordinates (i,j)
 * from starting cell (0,0) under the condition that you can only travel one step right or one step down.
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define F(i, a, b) for(int i=(int)a ; i<=(int)b ; i++)
#define RF(i, a, b) for(int i=(int)a ; i>=(int)b ; i--)

int main() {
    int X, Y;               //-- Matrix dimensions

    /* Insert matrix dimension */
    cin >> X;
    cin >> Y;

    int numWays[X][Y];
    numWays[0][0] = 1;

    /* Initialize first row */
    F(j, 1, Y-1)
        numWays[0][j] = 1;

    /* Initialize first column */
    F(i, 1, X-1)
        numWays[i][0] = 1;

    /* Find for others */
    F(i, 1, X-1)
        F(j, 1, Y-1)
            numWays[i][j] = numWays[i-1][j] + numWays[i][j-1];

    cout << "Number of ways to reach (" << X-1 << ", " << Y-1 << ") from (0, 0) = " << numWays[X-1][Y-1] << endl;

    return 0;
}
