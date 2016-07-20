#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Person {
    string fom1, fom2; // father or mother
    string gene;
};

map <string, Person> dataset;

string get(string name) {
    if (dataset[name].gene != "") return dataset[name].gene;

    string fom1 = dataset[dataset[name].fom1].gene = get(dataset[name].fom1);
    string fom2 = dataset[dataset[name].fom2].gene = get(dataset[name].fom2);

    if (fom1 == "dominant" || fom2 == "dominant" || (fom1 != "non-existent" && fom2 != "non-existent")) {
        if ( (fom1 == "dominant" && fom2 == "recessive") ||
             (fom2 == "dominant" && fom1 == "recessive") ||
             (fom1 == "dominant" && fom2 == "dominant")) {
                 dataset[name].gene = "dominant";
                 return "dominant";
        } else {
            dataset[name].gene = "recessive";
            return "recessive";
        }
    } else {
        dataset[name].gene = "non-existent";
        return "non-existent";
    }
}

int main() {
    int t; scanf("%d", &t);
    string name, info;
    while (t--) {
        cin >> name >> info;
        if (info == "non-existent" || info == "recessive" || info == "dominant")
            dataset[name].gene = info;
        else if (dataset[info].fom1 == "")
            dataset[info].fom1 = name;
        else
            dataset[info].fom2 = name;
    }

    for (map<string, Person>::iterator it = dataset.begin(); it != dataset.end(); ++it) {
        cout << it->first << " " << get(it->first) << endl;
    }
    return 0;
}
