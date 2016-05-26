#include <iostream>
using namespace std;
int main() {
    int t, money = 0; scanf("%d", &t);
    while (t--) {
        string input; cin >> input;
        if (input == "donate") {
            int temp; scanf("%d", &temp);
            money += temp;
        } else {
            printf("%d\n", money);
        }
    }
}
