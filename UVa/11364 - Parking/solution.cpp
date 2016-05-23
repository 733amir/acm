#include <iostream>

int main() {
    int c; scanf("%d", &c); // First counter
    while (c--) {
        int cc, min = 100, max = -1; scanf("%d", &cc); // Second counter
        while (cc--) {
            int t; scanf("%d", &t); // Temperary variable
            min = t < min ? t : min;
            max = t > max ? t : max;
        }
        printf("%d\n", 2 * (max - min));
    }
    return 0;
}
