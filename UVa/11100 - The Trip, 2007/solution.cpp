#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define loop(counter, start, end, step) for (int counter = start; counter < end; counter += step)
#define rloop(counter, start, end, step) for (int counter = start; counter > end; counter -= step)

using namespace std;

int n, bags[10000], mostRepeat, repeat;

int main() {
    // Put your code here
    scanf("%d", &n);
    while (n) {
        loop(i, 0, n, 1) scanf("%d", bags + i);

        sort(bags, bags + n);

        mostRepeat = repeat = 1;
        loop(i, 1, n, 1) {
            if (bags[i - 1] == bags[i]) ++repeat;
            else {
                mostRepeat = max(mostRepeat, repeat);
                repeat = 1;
            }
        }
        mostRepeat = max(mostRepeat, repeat);

        printf("%d\n", mostRepeat);
        loop(i, 0, mostRepeat, 1) {
            printf("%d", bags[i]);
            loop(j, i + mostRepeat, n, mostRepeat) printf(" %d", bags[j]);
            printf("\n");
        }

        scanf("%d", &n);
        if (n) printf("\n");
    }
    return 0;
}
