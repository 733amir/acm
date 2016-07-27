#include <iostream>

using namespace std;

int main() {
    int tc, nc, *nums, *countOfNums, sum, i, j; scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &nc);
        nums = new int[nc];
        countOfNums = new int[nc];
        for (i = 0; i != nc; ++i) {
            scanf("%d", &nums[i]);
            countOfNums[i] = 0;
            for (j = i - 1; j != -1; --j)
                if (nums[j] <= nums[i])
                    countOfNums[i]++;
        }
        sum = 0;
        for (i = 0; i < nc; ++i)
            sum += countOfNums[i];
        printf("%d\n", sum);
        delete[] nums;
        delete[] countOfNums;
    }
    return 0;
}
