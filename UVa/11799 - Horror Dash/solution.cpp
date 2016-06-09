#include <iostream>

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, max = 0; scanf("%d", &n);
        while (n--) {
            int temp; scanf("%d", &temp);
            if (temp > max) max = temp;
        }
        printf("Case %d: %d\n", i, max);
    }
    return 0;
}
