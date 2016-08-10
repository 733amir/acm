#include <iostream>
using namespace std;

int all[92][8], counter = 0; // 92 board, each have 8 columns
int row[8], board[8][8];

void eightQueen(int column) {
    if (column == 8) {
        for (int i = 0; i < 8; ++i)
            all[counter][i] = row[i];
        counter++;
    }

    bool isSafe;
    for (int i = 0; i < 8; ++i) {
        isSafe = true;
        for (int j = 0; j < column; ++j) {
            if (row[j] == i || j - row[j] == column - i || j + row[j] == column + i) {
                isSafe = false;
                break;
            }
        }
        if (isSafe) {
            row[column] = i;
            eightQueen(column + 1);
        }
    }
}

int main() {
    eightQueen(0);
    int tc; scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                scanf("%d", &board[i][j]);

        int max = 0, total;
        for (int i = 0; i < counter; ++i) {
            total = 0;
            for (int j = 0; j < 8; ++j)
                total += board[j][all[i][j]];
            if (total > max)
                max = total;
        }

        printf("%5d\n", max);
    }
    return 0;
}
