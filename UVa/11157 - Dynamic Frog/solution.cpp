#include <iostream>
#include <algorithm>
#include <vector>

#define loop(counter, start, end, step) for(int counter = start; counter < end; counter += step)

using namespace std;

int tc, n, d, stone, stonesSize, maximum, dist;
char type;
vector <int> stones;

int main() {
    scanf("%d\n", &tc);
    loop(i, 1, tc + 1, 1) {
        stones.clear();

        scanf("%d %d\n", &n, &d);
        stones.push_back(0);
        stones.push_back(d);

        loop(i, 0, n, 1) {
            if (i) scanf("%c%c-%d", &type, &type, &stone);
            else scanf("%c-%d", &type, &stone);

            stones.push_back(stone);
            if (type == 'B') stones.push_back(stone);
        }

        sort(stones.begin(), stones.end());

        maximum = 0;
        stonesSize = stones.size();
        loop(i, 0, stonesSize - 2, 1) {
            dist = stones[i + 2] - stones[i];
            if (dist > maximum) maximum = dist;
        }

        printf("Case %d: %d\n", i, maximum);
    }
    return 0;
}
