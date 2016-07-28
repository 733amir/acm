#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int fc, rc, *front, *rear, i, j;
    double biggest, *all;

    while (scanf("%d", &fc), fc) {
        front = new int[fc];
        scanf("%d", &rc);
        rear = new int[rc];
        all = new double[fc * rc];

        for (i = 0; i != fc; ++i) scanf("%d", &front[i]);
        for (i = 0; i != rc; ++i) scanf("%d", &rear[i]);

        for (i = 0; i != fc; ++i)
            for (j = 0; j != rc; ++j)
                all[i * rc + j] = double(front[i]) / rear[j];

        sort(all, all + fc * rc); // to make them adjacent

        biggest = 0;
        for (i = 1; i != fc * rc; ++i)
            if (all[i] / all[i - 1] > biggest)
                biggest = all[i] / all[i - 1];

        printf("%.2lf\n", biggest);

        delete[] all;
        delete[] front;
        delete[] rear;
    }
    return 0;
}
