import java.util.Scanner;

public class Main {
    private static int[] mainBoard = new int[8], selected = new int[8];
    private static int minimum;
    private static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int caseCounter = 1;
        while (in.hasNext()) {
            // Get the board from input
            for (int i = 0; i < 8; ++i)
                mainBoard[i] = in.nextInt() - 1;

            // Set minimum to a big number and find the minimum moves needed
            minimum = Integer.MAX_VALUE;
            findMinimumMove(0);

            System.out.println("Case " + caseCounter++ + ": " + minimum);
        }
    }

    private static void findMinimumMove(int column) {
        // A valid 8-queen, so updating minimum moves.
        if (column == 8) {
            int moveCount = 0;
            for (int i = 0; i < 8; ++i)
                if (mainBoard[i] - selected[i] != 0)
                    ++moveCount;
            if (moveCount < minimum)
                minimum = moveCount;
            return;
        }

        // Check safety of a cell,
        //   if is safe, set that column to that row and go for next column,
        //   if is not safe, go for next row in this column
        for (int i = 0; i < 8; ++i) {
            if (isSafe(column, i)) {
                selected[column] = i;
                findMinimumMove(column + 1);
            }
        }
    }

    private static boolean isSafe(int column, int row) {
        for (int i = 0; i < column; ++i) {
            if (selected[i] == row || // Existence of another queen with row = `row`
                    column - i == Math.abs(row - selected[i])) // Existence of another queen in same diagonal.
                return false;
        }
        return true;
    }
}
