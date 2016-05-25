#include <iostream>

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int num[3];
        scanf("%d%d%d", num, num+1, num+2);
        if ((num[0] < num[1] && num[1] < num[2]) || (num[0] > num[1] && num[1] > num[2]))
            printf("Case %d: %d\n", i, num[1]);
        else if ((num[0] < num[1] && num[0] > num[2]) || (num[0] > num[1] && num[0] < num[2]))
            printf("Case %d: %d\n", i, num[0]);
        else
            printf("Case %d: %d\n", i, num[2]);
    }
    return 0;
}
