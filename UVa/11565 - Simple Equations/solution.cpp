#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int tc, a, b, c, x, y, z, range;
    bool found;

    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &a, &b, &c);
        range = sqrt(c) + 1;
        found = false;
        for (x = -range; x != range && !found; ++x) {
            for (y = x + 1; y != range && !found; ++y) {
                if (x + y >= a || x * y >= b || x * x + y * y >= c) break;
                for (z = y + 1; z != range; ++z) {
                    if (x + y + z > a || x * y * z > b || x * x + y * y + z * z > c) break;
                    if (x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                        printf("%d %d %d\n", x, y, z);
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
            printf("No solution.\n");
    }
    return 0;
}
