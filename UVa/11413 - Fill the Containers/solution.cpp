#include <iostream>
using namespace std;

int n, m, vessels[1000];
bool mid;
long long start, stop;

int check(long long size) {
    long long total = 0, i = 0, counter = 1;
    while (i < n) {
        if (total + vessels[i] <= size) {
            total += vessels[i++];
        } else {
            ++counter;
            if (counter > m) return false;
            total = 0;
        }
    }
    return true;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", &vessels[i]);

        start = 0, stop = 10000000000;
        while (stop - start != 1) {
            mid = check((start + stop) / 2);
            if (mid)
                stop = (start + stop) / 2;
            else
                start = (start + stop) / 2;
        }
        printf("%lld\n", stop);
    }
}
