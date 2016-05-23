#include <iostream>

int main() {
    int c; scanf("%d", &c);
    while (c--) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%c\n", a > b ? '>' : (a < b ? '<' : '='));
    }
    return 0;
}
