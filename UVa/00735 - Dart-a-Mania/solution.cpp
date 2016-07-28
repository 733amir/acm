#include <iostream>
using namespace std;

int main() {
    int all[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
    int allSize = 43, score, i, j, k, combination, permutation, relation;

    while (scanf("%d", &score), score > 0) {
        if (score < 181) {
            combination = permutation = 0;
            for (i = 0; i != allSize; ++i)
                for (j = i; j != allSize; ++j)
                    for (k = j; k != allSize; ++k)
                        if (score == all[i] + all[j] + all[k]) {
                            combination++;
                            relation = (all[i] == all[j]) + (all[i] == all[k]) + (all[j] == all[k]);
                            if (relation == 0) permutation += 6;
                            else if (relation == 1) permutation += 3;
                            else permutation += 1;
                        }
            if (combination && permutation) {
                printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combination);
                printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutation);
            } else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        } else
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
