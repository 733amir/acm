#include <iostream>

int main() {
    int n;
    for (int i = 1;; i++) {
        scanf("%d", &n); if (n == 0) break;
        int treat = 0, in;
        while (n--) {
            scanf("%d", &in);
            treat += in == 0 ? -1 : 1;
        }
        printf("Case %d: %d\n", i, treat);
    }
    return 0;
}
