#include <iostream>
using namespace std;

int main() {
    int mile, rkm;
    double km;
    while (scanf("%d", &mile), mile) {
        km = mile * 1.6;
        rkm = km;
        printf("%.2f\n", min(km - rkm, rkm + 1 - km));
    }
    return 0;
}
