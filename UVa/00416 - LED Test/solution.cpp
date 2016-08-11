#include <iostream>
using namespace std;

int ledCount;
string led[10];
bool intact[10][7];

bool test(int l, string r) {
    string s = led[l];
    return ((intact[l][0] && s[0] == r[0]) || (!intact[l][0] && s[0] == 'N')) &&
           ((intact[l][1] && s[1] == r[1]) || (!intact[l][1] && s[1] == 'N')) &&
           ((intact[l][2] && s[2] == r[2]) || (!intact[l][2] && s[2] == 'N')) &&
           ((intact[l][3] && s[3] == r[3]) || (!intact[l][3] && s[3] == 'N')) &&
           ((intact[l][4] && s[4] == r[4]) || (!intact[l][4] && s[4] == 'N')) &&
           ((intact[l][5] && s[5] == r[5]) || (!intact[l][5] && s[5] == 'N')) &&
           ((intact[l][6] && s[6] == r[6]) || (!intact[l][6] && s[6] == 'N'));
}

bool is9(int l) { return test(l, "YYYYNYY"); }
bool is8(int l) { return test(l, "YYYYYYY"); }
bool is7(int l) { return test(l, "YYYNNNN"); }
bool is6(int l) { return test(l, "YNYYYYY"); }
bool is5(int l) { return test(l, "YNYYNYY"); }
bool is4(int l) { return test(l, "NYYNNYY"); }
bool is3(int l) { return test(l, "YYYYNNY"); }
bool is2(int l) { return test(l, "YYNYYNY"); }
bool is1(int l) { return test(l, "NYYNNNN"); }
bool is0(int l) { return test(l, "YYYYYYN"); }

bool isValid(int l = 0, int ln = -1) {
    if (l == ledCount) return true;

    bool r = false;

    if (!r && is9(l) && (ln == -1 || ln - 1 == 9)) r = r || isValid(l + 1, 9);
    if (!r && is8(l) && (ln == -1 || ln - 1 == 8)) r = r || isValid(l + 1, 8);
    if (!r && is7(l) && (ln == -1 || ln - 1 == 7)) r = r || isValid(l + 1, 7);
    if (!r && is6(l) && (ln == -1 || ln - 1 == 6)) r = r || isValid(l + 1, 6);
    if (!r && is5(l) && (ln == -1 || ln - 1 == 5)) r = r || isValid(l + 1, 5);
    if (!r && is4(l) && (ln == -1 || ln - 1 == 4)) r = r || isValid(l + 1, 4);
    if (!r && is3(l) && (ln == -1 || ln - 1 == 3)) r = r || isValid(l + 1, 3);
    if (!r && is2(l) && (ln == -1 || ln - 1 == 2)) r = r || isValid(l + 1, 2);
    if (!r && is1(l) && (ln == -1 || ln - 1 == 1)) r = r || isValid(l + 1, 1);
    if (!r && is0(l) && (ln == -1 || ln - 1 == 0)) r = r || isValid(l + 1, 0);

    return r;
}

int main() {
    while (scanf("%d", &ledCount), ledCount) {
        for (int i = 0; i < ledCount; ++i)
            for (int j = 0; j < 7; ++j)
                intact[i][j] = false;

        for (int i = 0; i < ledCount; ++i) {
            cin >> led[i];
            for (int j = i; j >= 0; --j)
                for (int k = 0; k < 7; k++)
                    if (led[i][k] == 'Y')
                        intact[j][k] = true;
        }
        printf("%s\n", isValid()? "MATCH": "MISMATCH");
    }
}
