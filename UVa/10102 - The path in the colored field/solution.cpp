#include <iostream>
using namespace std;

int main() {
    int m, i, j, k, l, max, min;
    char **box;

    while (scanf("%d", &m) != EOF) {
        box = new char*[m];
        for (i = 0; i != m; ++i) {
            box[i] = new char[m + 1];
            scanf("%s", box[i]);
        }

        max = 0;
        for (i = 0; i != m; ++i)
            for (j = 0; j != m; ++j)
                if (box[i][j] == '1') {
                    min = 2 * m;
                    for (k = 0; k != m; ++k)
                        for (l = 0; l != m; ++l)
                            if (box[k][l] == '3' && abs(i - k) + abs(j - l) < min)
                                min = abs(i - k) + abs(j - l);
                    if (min > max)
                        max = min;
                }

        printf("%d\n", max);

        for (i = 0; i != m; ++i)
            delete[] box[i];
        delete[] box;
    }
    return 0;
}
