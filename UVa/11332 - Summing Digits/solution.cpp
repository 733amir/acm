#include <iostream>

int main() {
    long long n; int t;
    while (scanf("%lld", &n), n) {
        t = 0;
        while (n) {
            t += n % 10;
            n /= 10;
            t = t % 10 + t / 10;
        }
        printf("%d\n", t);
    }
    return 0;
}
