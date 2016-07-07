#include <iostream>
using namespace std;

int main() {
    double h, u, d, f;
    while (scanf("%lf", &h), h) {
        scanf("%lf%lf%lf", &u, &d, &f);
        double ff = u * f / 100; // fatigue factor of first day
        double cur = 0;
        for (int day = 1;; day++) {
            cur += u > 0? u: 0; // snail never climbs down at day
            if (cur > h) {printf("success on day %d\n", day); break;}
            cur -= d;
            if (cur < 0) {printf("failure on day %d\n", day); break;}
            // failure happens at end of the night or start of next day
            else if (cur == 0) {printf("failure on day %d\n", day + 1); break;}
            u -= ff;
        }
    }
    return 0;
}
