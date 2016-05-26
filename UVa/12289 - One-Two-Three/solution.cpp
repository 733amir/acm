#include <iostream>
using namespace std;
int main() {
    int t; scanf("%d", &t);
    string input;
    while (t--) {
        cin >> input;
        if (input.length() == 5) printf("3\n");
        else if ((1 + (input[0] == 't') + (input[1] == 'w') + (input[2] == 'o')) >= 3) printf("2\n");
        else printf("1\n");
    }
    return 0;
}
