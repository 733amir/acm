#define SIZE 8
#include <iostream>
using namespace std;

// No queen => 0, A queen => queen number
int rows[SIZE], columns[SIZE], mainDiag[2 * SIZE - 1], subDiag[2 * SIZE - 1];
int where[SIZE], solNum = 1, row, column;

void add(int number) {
    if (number == column)
        add(number + 1);
    // All queens are set, so printing the information and preventing new recursive call.
    else if (number > SIZE) {
        if (solNum / 10 == 0) cout << ' ';
        cout << solNum << "     ";
        for (int i = 0; i < SIZE; i++) cout << ' ' << where[i];
        cout << endl;
        solNum++;
    } else for (int i = 0, j = number - 1; i < SIZE; i++) {
        if (rows[i]) continue; // There is a queen in this row.
        // There is a queen in this column.
        // Or rows[i], columns[j] is threated by queen on a diagonal.
        if (columns[j] || mainDiag[i + j] || subDiag[i - j + SIZE - 1]) continue;
        // Adding queen to rows[i], columns[j].
        rows[i] = columns[j] = mainDiag[i + j] = subDiag[i - j + SIZE - 1] = number;
        // Saving that each queen on column j is on row i.
        where[j] = i + 1;
        // Adding next queen.
        add(number + 1);
        // Remove this queen from rows[i], columns[j].
        rows[i] = columns[j] = mainDiag[i + j] = subDiag[i - j + SIZE - 1] = 0;
    }

}

int main() {
    int tcc; cin >> tcc;
    while (tcc--) {
        // Initializing variables
        solNum = 1;
        for (int i = 0; i < SIZE; i++) rows[i] = columns[i] = where[i] = 0;
        for (int i = 0; i < 2 * SIZE - 1; i++) mainDiag[i] = subDiag[i] = 0;

        // Get constant queen from stdin
        cin >> row >> column; row--; column--;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

        // Adding first queen here, becuase it will not move
        rows[row] = columns[column] = mainDiag[row + column] = subDiag[row - column + SIZE - 1] = 1;
        where[column] = row + 1;

        // Start adding queens from the second one
        column++;
        add(1);

        // A blank line between each test case
        if (tcc) cout << endl;
    }
    return 0;
}
