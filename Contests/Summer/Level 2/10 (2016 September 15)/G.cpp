#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define loop(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rloop(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
unsigned long long num[10], total, nom, den, gcd;
int tc, n;

unsigned long long GCD(unsigned long long a, unsigned long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc) {
        cin >> n;
        total = 1;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            total *= num[i];
        }

        den = 0;
        for (int i = 0; i < n; ++i)
            den += total / num[i];

        nom = total * n;

        gcd = GCD(max(nom, den), min(nom, den));

        cout << "Case " << cc << ": " << nom / gcd << '/' << den / gcd << endl;
    }
    return 0;
}
