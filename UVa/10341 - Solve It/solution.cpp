#include <iostream>
#include <math.h>
using namespace std;

int p, q, r, s, t, u;
double result, near;

double equation(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

int main() {
    while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF) {
        if (equation(0) * equation(1) > 0) printf("No solution\n");
        else if (equation(1) == 0) printf("1.0000\n");
        else if (equation(0) == 0) printf("0.0000\n");
        else {
            result = 0;
            for (int i = 1; i <= 15; ++i) {
                near = result;
                for (int j = 0; j < 10; ++j) {
                    if (equation(near + j / pow(10, i)) * equation(near + (j + 1) / pow(10, i)) < 0) {
                        result = near + j / pow(10, i);
                        break;
                    }
                }
            }
            printf("%.4lf\n", result);
        }
    }
    return 0;
}
