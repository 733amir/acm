#include <iostream>

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int a, b; scanf("%d%d", &a, &b); n--;
        int d = a - b, yes = 1;
        while (n--) {
            scanf("%d%d", &a, &b);
            if (d != a - b) yes = 0;
        }
        if (yes) printf("yes\n");
        else printf("no\n");
        if (t) printf("\n");
    }
    return 0;
}
