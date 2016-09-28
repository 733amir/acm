#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define l(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rl(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
int size, nums[10000];
int maximum;

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    while (cin >> size, size) {
        maximum = 0;
        nums[0] = 0;
        l(i, 1, size + 1, 1) {
            cin >> nums[i];
            nums[i] += nums[i - 1];

            l(j, 0, i, 1)
                if (nums[i] - nums[j] > maximum)
                    maximum = nums[i] - nums[j];
        }

        // l(i, 1, size + 1, 1)
        //     cout << nums[i] << ' ';
        // cout << endl;

        if (maximum <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << maximum << ".\n";
    }

    return 0;
}
