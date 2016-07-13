#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {

        // Get price for each character
        int chars[256] = {0}, price, charCount; cin >> charCount;
        unsigned char aChar;
        while (charCount--) {
            cin >> aChar >> price;
            chars[aChar] = price;
        }

        // Get the article and calculate the money
        int total = 0, lineCount; cin >> lineCount;
        string line;
        getline(cin, line); // move cursor to correct position
        while (lineCount--) {
            getline(cin, line);
            for (int i = 0; i < line.length(); i++)
                total += chars[(unsigned char)line[i]];
        }
        cout << total / 100 << '.' << (total / 10) % 10 << total % 10 << '$' << endl;
    }
    return 0;
}
