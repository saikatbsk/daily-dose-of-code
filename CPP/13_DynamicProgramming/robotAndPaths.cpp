/*
 * Problem statement: https://www.codechef.com/problems/CD1IT4
 */
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::memset;

#define F(i, a, b) for(int i=(int)a ; i<=(int)b ; i++)
#define RF(i, a, b) for(int i=(int)a ; i>=(int)b ; i--)
#define MOD 1000000007

int main() {
    int M, N, P;        //-- Number of rows, columns, and blocked cells
    int l, k;

    /* Input the number of rows, columns and blocked cells */
    cin >> M >> N >> P;

    long long Grid[M+1][N+1];

    /* Initialize all cells with 0 */
    memset(Grid, 0, sizeof(Grid));

    /* Input the blocked cells */
    F(i, 0, P-1) {
        cin >> l >> k;

        /* Initialize blocked cells with -1 */
        Grid[l][k] = -1;
    }

    /* Check if the first cell is reachable */
    if(Grid[1][1] == -1) {
        cout << "0" << endl;
        return 0;
    }

    /* Calculate number of ways for first column */
    F(i, 1, M) {
        if(Grid[i][1] == 0) Grid[i][1] = 1LL;
        else
            break;
    }

    /* Calculate number of ways for first row */
    F(i, 2, N) {
        if(Grid[1][i] == 0) Grid[1][i] = 1LL;
        else
            break;
    }

    /* Do the same for all others */
    F(i, 2, M) {
        F(j, 2, N) {
            if(Grid[i][j] == -1)
                continue;

            if(Grid[i-1][j] > 0) Grid[i][j] = (Grid[i][j] + Grid[i-1][j] + MOD) % MOD;
            if(Grid[i][j-1] > 0) Grid[i][j] = (Grid[i][j] + Grid[i][j-1] + MOD) % MOD;
        }
    }

    if(Grid[M][N] == -1) cout << "0" << endl;
    else
        cout << Grid[M][N];

    return 0;
}
