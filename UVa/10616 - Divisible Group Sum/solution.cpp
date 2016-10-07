#include <iostream>
#include <string.h>
#define endl '\n'

using namespace std;

// Put your variables here
int n, q, d, m, nums[200], i, table[205][15][45];

int dp(int i, int s, int sum) {
    if (s == m) return sum == 0;
    if (i == n) return 0;
    if (table[i][s][sum + d] == -1)
        table[i][s][sum + d] = dp(i + 1, s, sum) + dp(i + 1, s + 1, (sum + nums[i]) % d);
    return table[i][s][sum + d];
}

int main() {
    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    for (int counter = 1; (cin >> n >> q, n || q); ++counter) {
        cout << "SET " << counter << ":\n";
        for (i = 0; i < n; ++i) cin >> nums[i];
        for (i = 1; i <= q; ++i) {
            cout << "QUERY " << i << ": ";
            cin >> d >> m;
            memset(table, -1, sizeof(table));
            cout << dp(0, 0, 0) << endl;
        }
    }
    return 0;
}
