#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, y;
    vector <int> ys;
    while (scanf("%d", &k) != EOF) {
        // Initializing
        y = k + 1;
        ys.clear();

        // Searching for Y
        while (true) {
            int x = (y * k) / (y - k);
            if (x == (y * k * 1.0) / (y - k)) ys.push_back(y);
            if (x == y) break;
            y++;
        }

        // Printing
        printf("%d\n", ys.size());
        for (int i = 0; i != ys.size(); ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, (ys[i] * k) / (ys[i] - k), ys[i]);
    }
    return 0;
}
