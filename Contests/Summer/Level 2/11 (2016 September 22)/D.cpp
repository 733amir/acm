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
#define loop(counter, start, end, step) for(int counter = start; counter < end; counter += step)
#define rloop(counter, start, end, step) for(int counter = start; counter > end; counter -= step)
#define endl '\n'

using namespace std;

// Put your variables here
int isReliable[20][20], reliable[20], reliability[20];
int informatsCount, numOfAns, a, b, maximum;

void find(int person) {
    if (person == informatsCount) {
        int reliableCount = 0;
        for (int i = 0; i < informatsCount; ++i) {
            if (reliable[i] > 0)
                reliableCount++;
        }
        if (reliableCount > maximum) maximum = reliableCount;
        return;
    }

    bool collision = false;
    for (int i = 0; i < informatsCount; ++i) {
        collision = (isReliable[person][i] == -1 && reliable[i] > 0) ||
                    (isReliable[person][i] == 1 && (reliable[i] < 0 || reliability[i] == -1));
        if (collision) break;
    }

    cout << "Collision for " << person + 1 << " is " << collision << endl;
    cout << "And reliable state is " << reliable[person] << endl;

    if (!collision && reliability[person] != -1) {
        reliable[person]++;
        for (int i = 0; i < informatsCount; ++i)
            reliable[i] += isReliable[person][i];
        find(person + 1);
        for (int i = 0; i < informatsCount; ++i)
            reliable[i] -= isReliable[person][i];
        reliable[person]--;
    }
    if (reliable[person] <= 0) {
        reliable[person]--;
        find(person + 1);
    }
}

int main() {
    // Redirection, comment them for submiting
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    while (true) {
        cin >> informatsCount; if (informatsCount == 0) break;

        // reset variables
        for (int i = 0; i < informatsCount; ++i) {
            reliable[i] = reliability[i] = 0;
            for (int j = 0; j < informatsCount; ++j)
                isReliable[i][j] = 0;
        }
        maximum = 0;

        cin >> numOfAns;
        for (int i = 0; i < numOfAns; ++i) {
            cin >> a >> b;

            // if unreliable => no need to proccess the message
            if (reliability[a - 1] == -1) continue;

            // 100% unreliable
            if (a == -b || (isReliable[a - 1][abs(b) - 1] != (b < 0? -1: 1) && isReliable[a - 1][abs(b) - 1] != 0))
                reliability[a - 1] = -1;

            isReliable[a - 1][abs(b) - 1] = (b < 0? -1: 1);
        }

        // cout << "reliability: ";
        // for (int i = 0; i < informatsCount; ++i) {
        //     cout << reliability[i] << ' ';
        // } cout << endl;
        //
        // cout << "reliable: ";
        // for (int i = 0; i < informatsCount; ++i) {
        //     cout << reliable[i] << ' ';
        // } cout << endl;

        find(0);

        cout << maximum << endl;
    }
    return 0;
}
