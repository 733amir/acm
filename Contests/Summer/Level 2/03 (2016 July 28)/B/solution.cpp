#include <iostream>
using namespace std;

int main() {
    int s;
    long long int d, k;

    while (scanf("%d", &s) != EOF) {
        scanf("%lld", &d);

        k = 0;
        while (true) {
            if (((2 * s + k) * (k + 1)) / 2 >= d) break;
            ++k;
        }

        printf("%lld\n", s + k);
    }
    return 0;
}
