#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define l(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rl(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
int n, table[100][100], max_in_loop, maximum = -99999999, box;

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> n;
    l(i, 0, n, 1) l(j, 0, n, 1) {
        cin >> table[i][j];
        if (i) table[i][j] += table[i - 1][j];
        if (j) table[i][j] += table[i][j - 1];
        if (i && j) table[i][j] -= table[i - 1][j - 1];

        max_in_loop = table[i][j];
        l(ii, 0, i, 1) l(jj, 0, j, 1) {
            box = table[i][j];
            if (ii) box -= table[ii - 1][j];
            if (jj) box -= table[i][jj - 1];
            if (ii && jj) box += table[ii - 1][jj - 1];

            if (box > max_in_loop)
                max_in_loop = box;
        }

        if (max_in_loop > maximum) maximum = max_in_loop;
    }

    // l(i, 0, n, 1) {
    //     l(j, 0, n, 1) {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << maximum << endl;
    return 0;
}
