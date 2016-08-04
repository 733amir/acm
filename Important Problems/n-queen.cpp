#include <stdio.h>
#define SIZE 8

bool v[SIZE] /* Vertically */, md[SIZE * 2 - 1] /* Main Diagonal */, ad[SIZE * 2 - 1] /* Adjacent Diagonal */;
int counter, queens[SIZE]; // queens[row] = column

void reset() {
    int i = counter = 0;
    for (; i < SIZE; ++i) v[i] = md[i] = ad[i] = false;
    for (; i < SIZE * 2 - 1; ++i) md[i] = ad[i] = false;
}

void calculating(int row) {
    if (row == SIZE) {
        counter++;
        return;
    }
    for (int column = 0; column < SIZE; ++column) {
        if (!v[column] && !md[SIZE - 1 + row - column] && !ad[row + column]) {
            v[column] = md[SIZE - 1 + row - column] = ad[row + column] = true;
            queens[row] = column;
            calculating(row + 1);
            v[column] = md[SIZE - 1 + row - column] = ad[row + column] = false;
        }
    }
}

int main() {
    reset();
    calculating(0);
    printf("%d\n", counter);
    return 0;
}
