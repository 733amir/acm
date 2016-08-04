#include <iostream>
using namespace std;

int main() {
    int n, sc /* Song Count */, songs[20], total, closest, ones, onesOfBest;
    long long selector, best;

    while (scanf("%d%d", &n, &sc) != EOF) {
        for (int i = 0; i < sc; ++i) scanf("%d", &songs[i]);
        onesOfBest = closest = best = 0;
        for (selector = 0; selector < 1<<sc; ++selector) {
            ones = total = 0;
            for (int i = 0; selector >> i; ++i)
                if ((selector >> i) % 2) {
                    total += songs[i];
                    ++ones;
                }
            if ((closest == total && ones > onesOfBest) || (closest < total && total <= n)) {
                closest = total;
                best = selector;
                onesOfBest = ones;
            }
        }

        for (int i = 0; best >> i; ++i)
            if ((best >> i) % 2)
                printf("%d ", songs[i]);
        printf("sum:%d\n", closest);
    }
    return 0;
}
