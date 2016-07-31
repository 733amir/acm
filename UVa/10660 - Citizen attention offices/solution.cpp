#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int tc, areas[25], ac, i, j, k, l, m, n, distance;
    int minimum, mi, mj, mk, ml, mm;

    scanf("%d", &tc);
    while (tc--) {
        for (i = 0; i != 25; areas[i++] = 0);

        scanf("%d", &ac);
        while (ac--) {
            scanf("%d%d%d", &i, &j, &k);
            areas[i * 5 + j] = k;
        }

        minimum = INT_MAX;
        for (i = 0; i != 21; ++i)
            for (j = i + 1; j != 22; ++j)
                for (k = j + 1; k != 23; ++k)
                    for (l = k + 1; l != 24; ++l)
                        for (m = l + 1; m != 25; ++m) {
                            distance = 0;
                            for (n = 0; n != 25; ++n) {
                                if (areas[n] != 0) {
                                    distance += areas[n] * min({
                                        abs(n/5 - i/5) + abs(n%5 - i%5),
                                        abs(n/5 - j/5) + abs(n%5 - j%5),
                                        abs(n/5 - k/5) + abs(n%5 - k%5),
                                        abs(n/5 - l/5) + abs(n%5 - l%5),
                                        abs(n/5 - m/5) + abs(n%5 - m%5),
                                    });
                                }
                            }
                            if (distance < minimum) {
                                mi = i;
                                mj = j;
                                mk = k;
                                ml = l;
                                mm = m;
                                minimum = distance;
                            }
                        }

        printf("%d %d %d %d %d\n", mi, mj, mk, ml, mm);
    }
    return 0;
}
