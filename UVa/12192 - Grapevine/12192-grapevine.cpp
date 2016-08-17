#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n, m, h[500][500], q, l, u;
    int lower[500];
    int max, result;

    while (scanf("%d%d", &n, &m), n || m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &h[i][j]);
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &l, &u);
            for (int j = 0; j < n; ++j)
                lower[j] = lower_bound(h[j], h[j] + (j? lower[j - 1]: m), l) - h[j];

            max = 0;
            for (int j = 0; j < n; ++j) {
                result = 0;
                for (int k = 0; j + k < n && lower[j] + k < m && h[j+k][lower[j]+k] <= u; ++k)
                    ++result;
                if (max < result)
                    max = result;
            }
            printf("%d\n", max);
        }
        printf("-\n");
    }
}
