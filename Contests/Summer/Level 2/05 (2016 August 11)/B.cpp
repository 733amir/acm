#include <iostream>
#include <string>
using namespace std;

int k, n, p[10001], q[10001], factor, power;
string in;

int spaceCounter(string data) {
    int spaces = 0;
    for (int i = 0; i < data.length(); ++i)
        if (data[i] == ' ')
            ++spaces;
    return spaces;
}

void readNums(string data, int numsCount) {
    int stop;
    while ((stop = data.find(' ')) != string::npos) {
        p[numsCount--] = stoi(data.substr(0, stop));
        data = data.substr(stop + 1, data.length());
    }
    p[numsCount--] = stoi(data.substr(0, data.length()));
}

int main() {
    while (getline(cin, in)) {
        k = stoi(in);
        getline(cin, in);
        n = power = spaceCounter(in);
        readNums(in, n);

        while (power != 0) {
            factor = p[power];
            q[power - 1] = factor;
            p[power] = 0;
            p[--power] += factor * k;
        }

        printf("q(x):");
        for (int i = n - 1; i >= 0; --i)
            printf(" %d", q[i]);
        printf("\nr = %d\n\n", p[0]);
    }
    return 0;
}
