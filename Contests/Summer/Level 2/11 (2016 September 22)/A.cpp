#include <iostream>
#include <string.h>
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
int hour, minute, second, last = -1, current, ospeed, nspeed;
float dist;
char line[80];

int main() {
    // Redirection, comment them for submiting
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    // Put your code here
    while (scanf("%[^\n]\n", line) != EOF) {
        if (strlen(line) == 8) {
            sscanf(line, "%d:%d:%d", &hour, &minute, &second);
            current = hour * 3600 + minute * 60 + second;
            dist += (current - last) * ospeed * 1.0 / 3600;
            last = current;
            printf("%d%d:%d%d:%d%d %.2f km\n", hour / 10, hour % 10, minute / 10, minute % 10, second / 10, second % 10, dist);
        } else {
            sscanf(line, "%d:%d:%d %d", &hour, &minute, &second, &nspeed);
            if (last == -1) {
                last = hour * 3600 + minute * 60 + second;
                ospeed = nspeed;
            } else {
                current = hour * 3600 + minute * 60 + second;
                dist += (current - last) * ospeed * 1.0 / 3600;
                last = current;
                ospeed = nspeed;
            }
        }
    }
    return 0;
}
