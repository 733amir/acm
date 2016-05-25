#include <iostream>
#include <math.h>

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int num; scanf("%d", &num);
        int res = ((num * 567.0) / 9 + 7492) * 235 / 47 - 498;
        printf("%d\n", abs(res / 10) % 10); // A digit can't be negative
    }
    return 0;
}
