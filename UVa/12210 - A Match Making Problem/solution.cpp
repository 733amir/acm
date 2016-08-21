#include <iostream>
#include <math.h>

#define loop(counter, start, end, step) for (int counter = start; counter < end; counter += step)

using namespace std;

int b, s, bachelors[10000], spinsters[10000], youngestBachelor;

int main() {
    for (int i = 1; scanf("%d%d", &b, &s), b || s; ++i) {
        youngestBachelor = 60;
        loop(i, 0, b, 1) { scanf("%d", &bachelors[i]); youngestBachelor = min(youngestBachelor, bachelors[i]); }
        loop(i, 0, s, 1) scanf("%d", &spinsters[i]);

        if (b <= s)
            printf("Case %d: 0\n", i);
        else {
            printf("Case %d: %d %d\n", i, b - s, youngestBachelor);
        }
    }
    return 0;
}
