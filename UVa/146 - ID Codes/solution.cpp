#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string in;
    while (true)
    {
        cin >> in;
        if (in == "#")
            break;
        bool not_end = next_permutation(in.begin(), in.end());
        if (not_end)
            cout << in << endl;
        else
            cout << "No Successor" << endl;
    }
    return 0;
}
