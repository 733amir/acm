#include <iostream>
using namespace std;

bool start = true;

int main() {
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            if (start) printf("``");
            else printf("''");
            start = !start;
        } else printf("%c", c);
    }
}
