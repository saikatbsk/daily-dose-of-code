/*
 * Given a cost matrix Cost[][] where Cost[i][j] denotes the Cost of visiting cell with coordinates (i,j),
 * find a min-cost path to reach a cell (x,y) from cell (0,0) under the condition that you can only travel
 * one step right or one step down. (We assume that all costs are positive integers)
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::min;

#define F(i, a, b) for(int i=(int)a ; i<=(int)b ; i++)
#define RF(i, a, b) for(int i=(int)a ; i>=(int)b ; i--)

int main() {
    int X, Y;               //-- Matrix dimensions

    /* Insert matrix dimension */
    cin >> X;
    cin >> Y;

    int cost[X][Y];         //-- Cost matrix

    /* Insert all the costs for each cell in X x Y matrix */
    F(i, 0, X-1)
        F(j, 0, Y-1)
            cin >> cost[i][j];

    int minCost[X][Y];      //-- Minimum Cost matrix
    minCost[0][0] = cost[0][0];

    /* Calculate minCost for 1st row, assuming 0 indexing */
    F(j, 1, Y-1)
        minCost[0][j] = minCost[0][j-1] + cost[0][j];

    /* Calculate minCost for 1st column */
    F(i, 1, X-1)
        minCost[i][0] = minCost[i-1][0] + cost[i][0];

    /* Calculate minCost for all others */
    F(i, 1, X-1)
        F(j, 1, Y-1)
            minCost[i][j] = min(minCost[i-1][j], minCost[i][j-1]) + cost[i][j];


    cout << "Minimum cost from (0, 0) to (" << X-1 << ", " << Y-1 << ") = " << minCost[X-1][Y-1] << endl;

    return 0;
}
