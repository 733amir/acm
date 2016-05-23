#include <iostream>

int main() {
    int count; scanf("%d", &count);
    while (count--) {
        int n, m; scanf("%d%d", &n, &m);
        printf("%d\n", (n / 3) * (m / 3));
    }
}
