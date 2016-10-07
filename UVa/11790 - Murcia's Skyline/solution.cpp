#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>

#define endl '\n'

using namespace std;

// Put your variables here

int main() {
    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    int tc, n, *h, *w, *lis, *lds, mlis, mlds;
    h = new int[1000000];
    w = new int[1000000];
    lis = new int[1000000];
    lds = new int[1000000];

    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) cin >> h[j];
        for (int j = 0; j < n; ++j) { cin >> w[j]; lis[j] = lds[j] = w[j];}

        mlis = mlds = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < j; ++k) {
                if (h[k] < h[j] && lis[k] + w[j] > lis[j])
                    lis[j] = lis[k] + w[j];
                if (h[k] > h[j] && lds[k] + w[j] > lds[j])
                    lds[j] = lds[k] + w[j];
            }
            if (lis[j] > mlis) mlis = lis[j];
            if (lds[j] > mlds) mlds = lds[j];
        }

        cout << "Case " << i << ". ";
        if (mlis >= mlds) {
            cout << "Increasing (" << mlis << "). Decreasing (" << mlds << ").\n";
        } else {
            cout << "Decreasing (" << mlds << "). Increasing (" << mlis << ").\n";
        }
    }

    delete[] h;
    delete[] w;
    delete[] lis;
    delete[] lds;
    return 0;
}
