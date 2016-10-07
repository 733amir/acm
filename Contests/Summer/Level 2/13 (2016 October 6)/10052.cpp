#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#define endl '\n'

using namespace std;

// Put your variables here
int tc, n, m, i, j, k, l;
string name, A, B;
vector <string> names;
vector <string> groups[4];
map <string, vector<string>> data;


int main() {
    // Faster cin, cout. Remember, you should no longer use C scanf, printf, ... .
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Put your code here
    cin >> tc;
    for (int case_num = 1; case_num <= tc; ++case_num) {
        // Reading input
        cin >> n >> m;
        for (i = 0; i < n; ++i) { cin >> name; names.push_back(name); }
        for (i = 0; i < m; ++i) { cin >> A >> B; data[A].push_back(B); data[B].push_back(A); }

//        for (i = 0; i < n; ++i) {
//            cout << "For " << names[i] << endl;
//            vector <string> &conflicts = data[names[i]];
//            for (j = 0; j < conflicts.size(); ++j)
//                cout << conflicts[j] << ' ';
//            cout << endl;
//        }

        // Grouping
        for (i = 0; i < n; ++i) {
            name = names[i];
            for (j = 0; j < 4; ++j) {
                if (groups[j].empty()) { groups[j].push_back(name); break; }

                vector <string> &conflict = data[name];
                bool no_conflict = true;
                for (k = 0; k < groups[j].size(); ++k) {
                    for (l = 0; l < conflict.size(); ++l)
                        if (groups[j][k] == conflict[l]) {
                            no_conflict = false;
                            break;
                        }
                    if (!no_conflict) break;
                }
                if (no_conflict) { groups[j].push_back(name); break; }
            }
        }

        // if groups are less than 4 make new groups
        for (i = 0; i < 4; ++i)
            if (groups[i].empty())
                for (j = 0; j < 4; ++j)
                    if (groups[j].size() > 1) {
                        groups[i].push_back(groups[j][groups[j].size() - 1]);
                        groups[j].pop_back();
                        break;
                    }

        // Printing
        cout << "Case #" << case_num << endl;
        for (i = 0; i < 4; ++i) {
            cout << groups[i].size() << endl << groups[i][0];
            for (j = 1; j < groups[i].size(); ++j)
                cout << ' ' << groups[i][j];
            cout << endl;
            groups[i].clear();
        }

        names.clear();
        data.clear();

        if (case_num != tc) cout << endl;
    }

    return 0;
}