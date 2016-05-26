#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string input; cin >> input;
        if (input == "1" || input == "4" || input == "78") cout << '+' << endl;
        else if (input[input.length() - 2] == '3' && input[input.length() - 1] == '5') cout << '-' << endl;
        else if (input[0] == '9' && input[input.length() - 1] == '4') cout << '*' << endl;
        else if (input[0] == '1' && input[1] == '9' && input[2] == '0') cout << '?' << endl;
    }
    return 0;
}
