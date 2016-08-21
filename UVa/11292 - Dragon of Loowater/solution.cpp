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

// Put your variables here
int n, m, dragon[20000], knight[20000], head, man, total;

int main() {
    while(scanf("%d%d", &n, &m), n || m) {
        loop(i, 0, n, 1) scanf("%d", &dragon[i]);
        loop(i, 0, m, 1) scanf("%d", &knight[i]);

        if (m < n)
            printf("Loowater is doomed!\n");
        else {
            sort(dragon, dragon + n);
            sort(knight, knight + m);

            total = head = man = 0;
            while (head < n && man < m) {
                if (knight[man] >= dragon[head]) {
                    total += knight[man];
                    ++head;
                }
                ++man;
            }

            if (head == n)
                printf("%d\n", total);
            else
                printf("Loowater is doomed!\n");
        }
    }
    return 0;
}
