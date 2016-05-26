#include <iostream>

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; t--; i++) {
        int l, w, h; scanf("%d%d%d", &l, &w, &h);
        if (l <= 20 && w <= 20 && h <= 20) printf("Case %d: good\n", i);
        else printf("Case %d: bad\n", i);
    }
    return 0;
}
