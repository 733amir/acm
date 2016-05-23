#include <iostream>

int main() {
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d), a|b|c|d) {
        printf("%d\n",
            3 * 360 + // 3 full turns
            (
                (a - b > 0 ? a - b : a - b + 40) + // a to b clockwise
                (c - b > 0 ? c - b : c - b + 40) + // b to c counter clockwise
                (c - d > 0 ? c - d : c - d + 40)   // c to d clockwise
            ) * 9 // each unit on the lock is 9 degree
        );
    }
    return 0;
}
