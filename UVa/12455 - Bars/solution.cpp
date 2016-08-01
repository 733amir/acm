#include <iostream>
using namespace std;

int main() {
    int tc, n, p, bars[20], total;
    int i;
    long long selector;
    bool found;

    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &p);
        for (i = 0; i < p; ++i) scanf("%d", &bars[i]);

        found = false;
        for (selector = 0; selector < 1 << p; ++selector) {
            total = 0;
            for (i = 0; selector >> i; ++i)
                if ((selector >> i) % 2)
                    total += bars[i];
            if (total == n) {
                found = true;
                break;
            }
        }

        printf("%s\n", found? "YES": "NO");
    }
    return 0;
}
