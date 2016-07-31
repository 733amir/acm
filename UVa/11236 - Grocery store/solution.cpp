#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    for (a = 1; a != 2001; ++a)
        for (b = a; b != 2001; ++b) {
            if (a + b > 1998) break; // at least c = 1, d = 1
            for (c = b; c != 2001; ++c) {
                if (a + b + c > 1999) break; // at least d = 1
                if (a * b * c > 1000000) {
                    d = (1000000 * (a + b + c)) / (a * b * c - 1000000);
                    if (c <= d && a + b + c + d < 2001 && a + b + c + d == a * b * c * d / 1000000.0)
                        printf("%.2f %.2f %.2f %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
                }
            }
        }
    return 0;
}
