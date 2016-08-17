#include <iostream>
using namespace std;

int tc, n, counter;
long long coinA, coinB, total;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        total = 0, counter = 1;
        scanf("%lld", &coinA);
        for (int i = 1; i < n; ++i) {
            scanf("%lld", &coinB);
            if (coinA + total < coinB)
                total += coinA, ++counter;
            coinA = coinB;
        }
        printf("%d\n", counter);
    }
    return 0;
}
