#include <iostream>

int main() {
    int b, n, banks[20];
    while (scanf("%d%d", &b, &n), b || n) {
        for (int i = 0; i < b; i++) scanf("%d", &banks[i]);
        for (int i = 0; i < n; i++) {
            int from, to, money; scanf("%d%d%d", &from, &to, &money);
            banks[from - 1] -= money;
            banks[to - 1] += money;
        }
        int i;
        for (i = 0; i < b; i++) if (banks[i] < 0) break;
        if (i != b) printf("N\n");
        else printf("S\n");
    }
    return 0;
}
