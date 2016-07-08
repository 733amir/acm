#include <iostream>
#include <string>
using namespace std;

int main() {
    int numofreq, numofpro, tempi, besti, num = 1;
    string temps, bests;
    float tempf, bestf;
    bool first;
    while (cin >> numofreq >> numofpro, numofreq || numofpro) { // read until `numofreq` and `numofpro` become zero
        first = true;
        for (int i = 0; i < numofreq + 1; i++)
            getline(cin, temps);
        for (int i = 0; i < numofpro; i++) {
            getline(cin, temps);
            cin >> tempf >> tempi;
            if (first || tempi > besti || (tempi == besti && tempf < bestf)) {
                bests = temps;
                besti = tempi;
                bestf = tempf;
                first = false;
            }
            for (int j = 0; j < tempi + 1; j++)
                getline(cin, temps);
        }
        printf("%sRFP #%d\n%s\n", num == 1? "": "\n", num++, bests.c_str());
    }
    return 0;
}
