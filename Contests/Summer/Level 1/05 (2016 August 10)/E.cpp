#include <stdio.h>

int main() {
    int tc, a, b; scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", (a / 3) * (b / 3));
    }
}
