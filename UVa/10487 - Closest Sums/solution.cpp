#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int tn = 0, n, m, *nums, query, i, j, k, nearest;

    while (scanf("%d", &n), n) {
        // Get all numbers
        nums = new int[n];
        for (i = 0; i != n; ++i) scanf("%d", &nums[i]);
        sort(nums, nums + n);

        printf("Case %d:\n", ++tn);

        // Get all queries
        scanf("%d", &m);
        for (i = 0; i != m; ++i) {
            scanf("%d", &query);
            j = 0, k = n - 1;
            nearest = nums[j] + nums[k];
            while (j < k) {
                if (abs(nums[j] + nums[k] - query) < abs(nearest - query))
                    nearest = nums[j] + nums[k];
                if (nums[j] + nums[k] < query)
                    ++j;
                else if (nums[j] + nums[k] > query)
                    --k;
                else
                    break;
            }
            printf("Closest sum to %d is %d.\n", query, nearest);
        }

        delete[] nums;
    }
    return 0;
}
