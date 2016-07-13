#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int numbers[3000] = {0}, diffs[3000] = {0}, jolly = true;
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
            if (i > 0)
                diffs[abs(numbers[i] - numbers[i - 1])] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (diffs[i] != 1) {
                cout << "Not jolly\n";
                jolly = false;
                break;
            }
        }
        if (jolly)
            cout << "Jolly\n";
    }
    return 0;
}
