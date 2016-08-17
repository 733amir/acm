#include <iostream>
using namespace std;

int tc, n, *rungs, start, stop, mid;
bool midCheck;

bool check(int size) {
    int distance;
    for (int i = 1; i <= n; ++i) {
        distance = rungs[i] - rungs[i - 1];
        if (distance == size)
            --size;
        else if (distance > size)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &tc);
    for (int i = 1; i <= tc; ++i) {
        scanf("%d", &n);
        rungs = new int[n + 1];
        rungs[0] = 0;
        for (int j = 1; j <= n; ++j) scanf("%d", &rungs[j]);

        start = 0, stop = 10000001;
        while (stop - start != 1) {
            mid = (start + stop) / 2;
            midCheck = check(mid);
            if (midCheck)
                stop = mid;
            else
                start = mid;
        }

        printf("Case %d: %d\n", i, stop);

        delete[] rungs;
    }
    return 0;
}
