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
int tc, occ, boundry;
string x, z;

void counter(int xi, int zi) {
    if (zi == z.length()) {
        occ++;
        return;
    }

    boundry = x.length() - (z.length() - zi - 1);

    while (xi < boundry)
        if (x[xi++] == z[zi])
            counter(xi, zi + 1);
}

int main() {
    // Redirection, comment them for submiting
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;

    while (tc--) {
        cin >> x >> z;
        occ = 0;
        counter(0, 0);
        cout << occ << endl;
    }
    return 0;
}
