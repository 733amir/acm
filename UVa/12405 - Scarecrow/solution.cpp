#include <iostream>
using namespace std;

int tc, n, counter, scarecrows;
char feild[100];

int main() {
    scanf("%d", &tc);
    for (int i = 1; i <= tc; ++i) {
        scanf("%d", &n);
        scanf("%s", feild);

        counter = scarecrows = 0;
        for (int i = 0; i < n; ++i) {
            if (feild[i] == '.') {
                if (i > 1) {
                    if (feild[i - 1] != 's' && feild[i - 2] != 's') {
                        feild[i] = 's';
                        ++scarecrows;
                    }
                } else if (i > 0) {
                    if (feild[i - 1] != 's') {
                        feild[i] = 's';
                        ++scarecrows;
                    }
                } else {
                    feild[i] = 's';
                    ++scarecrows;
                }
            }
        }

        printf("Case %d: %d\n", i, scarecrows);
    }
    return 0;
}
