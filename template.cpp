#define LOG true
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T> void l(T message, char end='\n') { if (!LOG) return; cout << message << end; }
template <typename T> void l(int logNumber, T message, char end='\n') { if (!LOG) return; cout << "Log " << logNumber << " Starts :" << endl; cout << message << end; }

int main() {

    return 0;
}
