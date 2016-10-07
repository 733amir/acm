#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#define endl '\n'
#define lowest -999999999

using namespace std;

// Put your variables here
struct meteoric {
    int x, y, a, b;
    double in, out;
};

int tc, w, h, n;
meteoric m[200000];
bool started[200000];

void cal_time(int i) {
    double left = lowest, right = lowest, up = lowest, down = lowest;

    // left && right
    if (m[i].a != 0) {
        left = double(0 - m[i].x) / m[i].a;
        if (0 > m[i].y + left * m[i].b || m[i].y + left * m[i].b > h)
            left = lowest;
        right = double(w - m[i].x) / m[i].a;
        if (0 > m[i].y + right * m[i].b || m[i].y + right * m[i].b > h)
            right = lowest;
    } else if (m[i].x == 0 || m[i].x == w) {
        m[i].in = m[i].out = 0;
        return;
    }
    // up && down
    if (m[i].b != 0) {
        down = double(0 - m[i].y) / m[i].b;
        if (0 > m[i].x + down * m[i].a || m[i].x + down * m[i].a > w)
            down = lowest;
        up = double(h - m[i].y) / m[i].b;
        if (0 > m[i].x + up * m[i].a || m[i].x + up * m[i].a > w)
            up = lowest;
    } else if (m[i].y == 0 || m[i].y == h) {
        m[i].in = m[i].out = 0;
        return;
    }

    m[i].out = max({left, right, up, down});
    m[i].in = min({left, right, up, down}, [](const double& d1, const double& d2) {
        if (d1 == lowest) return false;
        if (d2 == lowest) return true;
        return d1 < d2;
    });
    if (m[i].in < 0) m[i].in = 0;
}

int main() {
    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;
    while (tc--) {
        // Reading input
        cin >> w >> h >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m[i].x >> m[i].y >> m[i].a >> m[i].b;
            cal_time(i);
//            cout << "in: " << m[i].in << " out: " << m[i].out << endl;
        }

        sort(m, m + n, [](meteoric a, meteoric b) {
            return a.in < b.in;
        });

        int counter = 0, max = 0;
        for (int i = 0; i < n; ++i) {

        }
    }
    return 0;
}