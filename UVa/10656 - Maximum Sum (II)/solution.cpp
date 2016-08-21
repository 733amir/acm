#include <iostream>
#define loop(counter, start, end, step) for (int counter = start; counter < end; counter += step)

using namespace std;

int n, input;
bool any, first;

int main() {
    while (scanf("%d", &n), n) {
        any = !(first = true);
        loop(i, 0, n, 1) {
            scanf("%d", &input);
            if (input) {
                any = true;
                if (first)
                    printf("%d", input), first = false;
                else
                    printf(" %d", input);
            }
        }
        printf("%s\n", any? "": "0");
    }
    return 0;
}
