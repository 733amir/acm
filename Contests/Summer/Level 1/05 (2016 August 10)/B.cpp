#include <iostream>
using namespace std;

int height[10000];

int main() {
    int l, h, r;
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        for (int i = l - 1; i < r - 1; ++i)
            if (height[i] < h)
                height[i] = h;
    }
    printf("%d %d", 1, height[0]);
    for (int i = 1; i < 10000; ++i)
        if (height[i - 1] != height[i])
            printf(" %d %d", i + 1, height[i]);
    printf("\n");
    return 0;
}
