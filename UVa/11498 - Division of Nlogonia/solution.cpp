#include <iostream>

int main() {
    int k, n, m;
    while (scanf("%d", &k), k) {
        scanf("%d%d", &n, &m);
        int x, y;
        while (k--) {
            scanf("%d%d", &x, &y);
            if (x == n || y == m)
                printf("divisa\n");
            else
                printf("%c%c\n", y > m ? 'N' : 'S', x > n ? 'E' : 'O');
        }
    }
    return 0;
}
