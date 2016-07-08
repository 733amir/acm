#include <iostream>
#include <string>
using namespace std;

int main() {
    int l;
    string cur, in;
    while (cin >> l, l) {
        cur = "+x";
        for (int i = 0; i < l - 1; i++) {
            cin >> in;
            if (in == "No") continue;
            if (cur == "+x") cur = in;
            else if (cur == "-x") {
                cur.erase();
                cur.push_back(in[0] == '+'? '-': '+');
                cur.push_back(in[1]);
            } else if (cur == "+y") {
                if (in[1] == 'z') continue;
                cur.erase();
                cur.push_back(in[0] == '+'? '-': '+');
                cur.push_back('x');
            } else if (cur == "-y") {
                if (in[1] == 'z') continue;
                cur.erase();
                cur.push_back(in[0]);
                cur.push_back('x');
            } else if (cur == "+z") {
                if (in[1] == 'y') continue;
                cur.erase();
                cur.push_back(in[0] == '+'? '-': '+');
                cur.push_back('x');
            } else if (cur == "-z") {
                if (in[1] == 'y') continue;
                cur.erase();
                cur.push_back(in[0]);
                cur.push_back('x');
            }
        }
        cout << cur << endl;
    }
    return 0;
}
