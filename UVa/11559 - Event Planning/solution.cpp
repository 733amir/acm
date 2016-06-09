#include <iostream>
#include <limits.h>

int main() {
    int n, b, h, w, min;
    while (scanf("%d%d%d%d", &n, &b, &h, &w) != EOF) {
        min = INT_MAX;
        for (int i = 0; i < h; i++) {
            int price, room; scanf("%d", &price);
            for (int j = 0; j < w; j++) {
                scanf("%d", &room);
                if (room >= n && n * price < min)
                    min = n * price;
            }
        }
        if (min <= b) printf("%d\n", min);
        else printf("stay home\n");
    }
    return 0;
}
