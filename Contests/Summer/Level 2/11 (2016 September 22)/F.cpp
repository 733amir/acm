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
#define loop(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rloop(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
int t, preambleCount, preamble[60], table[60], n, p[1000000], q[1000000], a, b, c, d, e, f, m;

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> preambleCount;
        for (int j = 0; j < preambleCount; ++j) cin >> preamble[j];
        cin >> n >> p[0] >> q[0] >> a >> b >> c >> d >> e >> f >> m;

        // build the table
        int pos = 2, cnd = 0;
        table[0] = -1;
        table[1] = 0;
        while (pos < preambleCount) {
            if (preamble[pos - 1] == preamble[cnd]) {
                table[pos] = cnd + 1;
                ++cnd; ++pos;
            } else if (cnd > 0) {
                cnd = table[cnd];
            } else {
                table[pos] = 0;
                ++pos;
            }
        }

        // build p and q
        for (int j = 1; j <= n; ++j) {
            p[j] = (a * p[j - 1] + b * q[j - 1] + c) % m;
            q[j] = (d * p[j - 1] + e * q[j - 1] + f) % m;
            if (p[j] > q[j]) swap(p[j], q[j]);
        }

        // counting matches
        int j = 1, k = 0, counter = 0;
        while (j + k <= n) {
            if (p[j + k] <= preamble[k] && preamble[k] <= q[j + k]) {
                if (k == preambleCount - 1) { ++counter; ++j; k = 0; }
                else ++k;
            } else {
                if (table[k] > -1) {
                    j = j + k - table[k];
                    k = table[k];
                } else {
                    ++j;
                    k = 0;
                }
            }
        }

        cout << "Case " << i << ": " << counter << endl;
    }
    return 0;
}
