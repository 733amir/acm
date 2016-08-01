/*   This question, in another word. There is a square of size `n * n` fulled with boxes of size `1 * 1`.
 * Each box has a value. You are about to find `n` boxes that each two of the have different row and column,
 * and total value of those boxes is the minimum possible one.
 */
#include <iostream>
using namespace std;

int table[8][8], minimum, picked[8] /* Which column selected for each row */, size;
bool choosedRow[8], choosedColumn[8]; // Is that row or column is selected before or not.

void select(int count, int start = 0) {
    // If all of them selected, find the total and update minimum
    if (count == 0) {
        int total = 0;
        for (int i = 0; i < size; ++i)
            total += table[i][picked[i]];
        if (minimum > total) minimum = total;
        return;
    }
    // Find the first unselected row and column, select it, call `select` to find next box to select.
    for (int i = start; i < size * size; ++i) {
        if (!choosedRow[i / size] && !choosedColumn[i % size]) {
            // Selecting this box
            choosedRow[i / size] = choosedColumn[i % size] = true;
            picked[i / size] = i % size;
            // Call for further searching
            select(count - 1, i + 1);
            // Unselecring this box
            choosedRow[i / size] = choosedColumn[i % size] = false;
            picked[i / size] = -1;
        }
    }
}

int main() {
    int tc; scanf("%d", &tc); // test count
    while (tc--) {
        scanf("%d", &size); // Get size of grid
        // Get values in the grid
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                scanf("%d", &table[i][j]);

        // Reset value of variables
        minimum = 100000; // Maximum possible value is 64000
        for (int i = 0; i < size; ++i) picked[i] = -1, choosedRow[i] = choosedColumn[i] = false;

        select(size);

        printf("%d\n", minimum);
    }
    return 0;
}
