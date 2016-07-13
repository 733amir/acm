#define LOG true
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T> void l(T message, char end='\n') { if (!LOG) return; cout << message << end; }
template <typename T> void l(int logNumber, T message, char end='\n') { if (!LOG) return; cout << "Log " << logNumber << " Starts :" << endl; cout << message << end; }

struct Soldier {
    int right, left;
    string status; // Alive or Dead
};

int main() {
    int s, b;
    while (cin >> s >> b, s || b) { // Get count of soldiers
        // Initializing soldiers
        Soldier *soldiers = new Soldier[s];
        for (int i = 0; i < s; i++) {
            soldiers[i].left  = i - 1; // => leftmost.left = -1
            soldiers[i].right = i + 1; // => rightmost.right = s
            soldiers[i].status = "Alive";
        }

        // Processing reports
        for (int i = 0; i < b; i++) {
            // Get left and right, Make them appropriate for zero base usage
            int left, right; cin >> left >> right; left--; right--;

            // Update status of every soldier from the report
            for (int j = left; j <= right; j++) {
                soldiers[j].left = left - 1;
                soldiers[j].right = right + 1;
                soldiers[j].status = "Dead";
            }

            // Find nearest left alive soldier
            while (true) {
                if (left == -1 || soldiers[left].status == "Alive")
                    break;
                else
                    left = soldiers[left].left;
            }
            if (left == -1)
                cout << "* ";
            else
                cout << left + 1 << ' ';

            // Find nearest right alive soldier
            while (true) {
                if (right == s || soldiers[right].status == "Alive")
                    break;
                else
                    right = soldiers[right].right;
            }
            if (right == s)
                cout << "*\n";
            else
                cout << right + 1 << endl;
        }
        cout << '-' << endl;
        delete[] soldiers;
    }
    return 0;
}
