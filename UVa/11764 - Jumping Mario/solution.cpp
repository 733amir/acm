#include <iostream>

int main() {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, low = 0, high = 0, a, b; scanf("%d%d", &n, &a);
        while (--n) {
            scanf("%d", &b);
            if (a < b) high++; else if (a > b) low++;
            a = b;
        }
        printf("Case %d: %d %d\n", i + 1, high, low);
    }
    return 0;
}
