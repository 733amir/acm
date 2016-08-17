#include <iostream>
#include <algorithm>
using namespace std;

int n, d, r, mor[100], eve[100], total;

int main() {
    while (scanf("%d%d%d", &n, &d, &r), n || d || r) {
        for (int i = 0; i < n; ++i) scanf("%d", &mor[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &eve[i]);

        sort(mor, mor + n);
        sort(eve, eve + n);

        total = 0;
        for (int i = 0; i < n; ++i)
            total += r * max(mor[i] + eve[n - i - 1] - d, 0);

        printf("%d\n", total);
    }
    return 0;
}
