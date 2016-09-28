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
int tc, n, two_n, number, table[150][150], box;
int max_in_loop, maximum;

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;
    while (tc--) {
        // Get data from input
        cin >> n;
        two_n = 2 * n;
        l(i, 0, n, 1) l(j, 0, n, 1) {
            cin >> number;
            table[i][j] = table[i + n][j] = table[i][j + n] = table[i + n][j + n] = number;
        }

        // cout << "Table:\n";
        // l(i, 0, two_n, 1) {
        //     l(j, 0, two_n, 1)
        //         cout << table[i][j] << ' ';
        //     cout << endl;
        // }

        // Calculating sum in (2n)^2
        l(i, 0, two_n, 1) l(j, 0, two_n, 1) {
            if (i) table[i][j] += table[i - 1][j];
            if (j) table[i][j] += table[i][j - 1];
            if (i && j) table[i][j] -= table[i - 1][j - 1];
        }

        // cout << "Calculated Table:\n";
        // l(i, 0, two_n, 1) {
        //     l(j, 0, two_n, 1)
        //         cout << table[i][j] << ' ';
        //     cout << endl;
        // }

        // best rectangle
        maximum = -9999999;
        l(i, 0, two_n, 1) {
            l(j, 0, two_n, 1) {
                max_in_loop = -9999999;
                l(ii, max(0, i - n + 1), i + 1, 1) {
                    l(jj, max(0, j - n + 1), j + 1, 1) {
                        box = table[i][j];
                        if (ii) box -= table[ii - 1][j];
                        if (jj) box -= table[i][jj - 1];
                        if (ii && jj) box += table[ii - 1][jj - 1];
                        if (box > max_in_loop) max_in_loop = box;
                    }
                }
                if (max_in_loop > maximum) maximum = max_in_loop;
            }
        }

        cout << maximum << endl;
    }
    return 0;
}
