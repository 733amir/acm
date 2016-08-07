#include <iostream>
#include <math.h>
#include <string>
#include <map>
using namespace std;

int t, n, numbers[12], total, j;
bool first;
string out;
map <string, bool> exist;

int main() {
    while (scanf("%d%d", &t, &n), n) {
        for (int i = n - 1; i >= 0; --i)
            scanf("%d", &numbers[i]);

        printf("Sums of %d:\n", t);

        first = true;
        exist.clear();
        for (int i = pow(2, n) - 1; i >= 0; --i) {
            total = 0;
            for (j = 0; i >> j; ++j)
                if ((i >> j) % 2)
                    total += numbers[j];
            if (total == t) {
                first = true;
                out.clear();
                while (j--)
                    if ((i >> j) % 2) {
                        if (!first) out.append("+");
                        else first = false;
                        out.append(to_string(numbers[j]));
                    }
                if (exist.find(out) == exist.end()) {
                    printf("%s\n", out.data());
                    exist[out] = true;
                }
            }
        }
        if (first)
            printf("NONE\n");
    }
}
