#define LOG true
#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename T> void l(T message, char end='\n') { if (!LOG) return; cout << message << end; }
template <typename T> void l(int logNumber, T message, char end='\n') { if (!LOG) return; cout << "Log " << logNumber << " Starts :" << endl; cout << message << end; }

int main ()
{
    map <string,string> dic;
    string line, eng, foreign, word;

    // Get dictinary
    while (true) {
        getline(cin, line);
        if (line == "") break;
        eng = line.substr(0, line.find(" "));
        foreign = line.substr(line.find(" ") + 1, line.length());
        // l(eng, ' '); l(foreign, '.');
        dic[foreign] = eng;
    }

    // Get words
    while (cin >> word) {
        if (dic[word] == "") cout << "eh" << endl;
        else cout << dic[word] << endl;
    }
    return 0;
}
