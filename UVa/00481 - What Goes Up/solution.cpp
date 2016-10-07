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

#define SIZE 1000000

using namespace std;

// Put your variables here
int numbers[SIZE], size, lis_to_here[SIZE], pre[SIZE], maximum;
vector <int> lis(1000000);

int main() {
    // Redirection, comment them for submiting
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    // Get data from input
    size = 0;
    while (cin >> numbers[size]) {
        lis_to_here[size] = 1;
        pre[size] = -1;
        ++size;
    }

    // cout << "Inputed numbers:\n";
    // for (int i = 0; i < size; ++i) cout << numbers[i] << ' ';
    // cout << endl;

    // Finding stricly increasing subsequence
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numbers[j] < numbers[i] && lis_to_here[j] + 1 >= lis_to_here[i]) {
                lis_to_here[i] = lis_to_here[j] + 1;
                pre[i] = j;
            }
        }
    }

    // cout << "lis_to_here:\n";
    // for (int i = 0; i < size; ++i)
    //     cout << lis_to_here[i] << ' ';
    // cout << endl;
    //
    // cout << "pre:\n";
    // for (int i = 0; i < size; ++i)
    //     cout << pre[i] << ' ';
    // cout << endl;

    // Printing LIS
    maximum = 0;
    for (int i = 1; i < size; ++i)
        if (lis_to_here[maximum] <= lis_to_here[i])
            maximum = i;

    while (maximum != -1) {
        lis.push_back(numbers[maximum]);
        maximum = pre[maximum];
    }

    cout << lis.size() << "\n-\n";
    for (int i = lis.size() - 1; i >= 0; --i)
        cout << lis[i] << endl;
    return 0;
}
