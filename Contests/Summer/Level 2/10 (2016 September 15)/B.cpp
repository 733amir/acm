#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define loop(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rloop(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
int tc, l, c, table[40][10], antena, minimum;
char sweden[40][10];
bool noantena;

int main() {
    // Redirection, comment them for submiting
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;
    while (tc--) {
        cin >> l >> c;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> sweden[i][j];
                table[i][j] = 0;
            }
        }

        antena = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                if (sweden[i][j] != '*') continue;
                noantena = true;
                if (i > 0 && sweden[i - 1][j] == '*') {noantena = false;}
                if (i < l - 1 && sweden[i + 1][j] == '*') {table[i][j]++; table[i + 1][j]++; antena++; noantena = false;}
                if (j > 0 && sweden[i][j - 1] == '*') {noantena = false;}
                if (j < c - 1 && sweden[i][j + 1] == '*') {table[i][j]++; table[i][j + 1]++; antena++; noantena = false;}
                if (noantena) { table[i][j]++; antena++; }
            }
        }

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << table[i][j];
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                if (table[i][j] < 2) continue;
                // if (i > 0 && table[i - 1][j] > 1) {table[i][j]--; table[i - 1][j]--; antena--;}
                if (i < l - 1 && table[i + 1][j] > 1) {
                    minimum = min(table[i][j], table[i + 1][j]) - 1;
                    table[i][j] -= minimum;
                    table[i + 1][j] -= minimum;
                    antena -= minimum;
                }
                // if (j > 0 && table[i][j - 1] > 1) {table[i][j]--; table[i][j - 1]--; antena--;}
                if (j < c - 1 && table[i][j + 1] > 1) {
                    minimum = min(table[i][j], table[i][j + 1]) - 1;
                    table[i][j] -= minimum;
                    table[i][j + 1] -= minimum;
                    antena -= minimum;
                }
            }
        }

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << table[i][j];
            }
            cout << endl;
        }

        cout << antena << endl;
    }
    return 0;
}
