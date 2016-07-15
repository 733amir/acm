#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long tcc, degree, coefficient[20], d, k; scanf("%lld", &tcc);
    long long n, Bk;
    while (tcc--) {
        // reading numbers from stdin
        scanf("%lld", &degree);
        for (int i = 0; i <= degree; i++) scanf("%lld", &coefficient[i]);
        scanf("%lld%lld", &d, &k);

        // finding n in equation Bk = An
        n = round(pow((2.0 * k) / d, 0.5));

        // calculating nth element in A sequence
        Bk = 0;
        for (int i = 0; i <= degree; i++)
            Bk += coefficient[i] * pow(n, i);

        printf("%lld\n", Bk);
    }
    return 0;
}
