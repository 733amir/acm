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
    int tc, n, nums[2000], lis[2000], lds[2000], max, temp;

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            lis[i] = lds[i] = 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j] && lis[i] <= lis[j])
                    lis[i] = lis[j] + 1;
                if (nums[i] < nums[j] && lds[i] <= lds[j])
                    lds[i] = lds[j] + 1;
            }
        }

        max = 0;
        for (int i = 0; i < n; ++i) {
            temp = lis[i] + lds[i] - 1;
            if (temp > max) max = temp;
        }

        cout << max << endl;
    }
    return 0;
}
