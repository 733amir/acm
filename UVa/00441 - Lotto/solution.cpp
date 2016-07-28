#include <iostream>
using namespace std;

int main() {
    int k, nums[12], i, j, l, m, n, p;
    bool first = true;

    while (scanf("%d", &k), k) {
        if (first) first = false;
        else printf("\n");

        for (i = 0; i != k; ++i) scanf("%d", &nums[i]);

        for (i = 0; i != k - 5; ++i)
            for (j = i + 1; j != k - 4; ++j)
                for (l = j + 1; l != k - 3; ++l)
                    for (m = l + 1; m != k - 2; ++m)
                        for (n = m + 1; n != k - 1; ++n)
                            for (p = n + 1; p != k; ++p)
                                printf("%d %d %d %d %d %d\n", nums[i], nums[j], nums[l], nums[m], nums[n], nums[p]);
    }
    return 0;
}
