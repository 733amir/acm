#include <iostream>

int main() {
    char c;
    bool start = true;
    while (scanf("%c", &c) != EOF) {
        if (c == '"' && start){
            printf("%s", "``");
            start = !start;
        } else if (c == '"' && !start) {
            printf("%s", "''");
            start = !start;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}
