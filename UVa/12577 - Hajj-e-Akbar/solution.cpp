#include <stdio.h>
#include <string.h>

int main() {
    for (int i = 1;; i++) {
        char input[10]; scanf("%s", input);
        if (strcmp(input, "*") == 0) break;
        else if (strcmp(input, "Hajj") == 0) printf("Case %d: Hajj-e-Akbar\n", i);
        else printf("Case %d: Hajj-e-Asghar\n", i);
    }
    return 0;
}
