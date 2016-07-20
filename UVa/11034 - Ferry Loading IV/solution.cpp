#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main() {
    int tc, l, m, size;
    char side[10];
    vector <int> left, right;

    scanf("%d", &tc);
    while (tc--) {
        // Get information
        scanf("%d%d", &l, &m);
        for (int i = 0; i != m; ++i) {
            scanf("%d%s", &size, side);
            if (strcmp(side, "right") == 0)
                right.push_back(size);
            else
                left.push_back(size);
        }

        // Calculate how many times ferry should cross the river
        int cross = 0, curLen = 0;
        bool isLeft = true;
        vector <int> *queue;
        l *= 100; // Convert meters to centimeters
        while (!(right.empty() && left.empty())) {
            queue = isLeft? &left: &right;
            if (!queue->empty()) {
                curLen += queue->front();
                if (curLen > l) {
                    curLen = 0;
                    cross++;
                    isLeft = !isLeft;
                } else {
                    queue->erase(queue->begin());
                }
            } else {
                curLen = 0;
                cross++;
                isLeft = !isLeft;
            }
        }
        printf("%d\n", cross + 1);
    }
    return 0;
}
