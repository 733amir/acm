import java.util.Scanner;

public class UVa00524 {
    private static StringBuilder out = new StringBuilder();
    private static Scanner in = new Scanner(System.in);

    private static final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    private static int n = 0;
    private static int[] circle = new int[16];
    private static boolean[] picked = new boolean[16];

    public static void main(String[] args) {
        picked[0] = true;
        circle[0] = 1;

        int caseCounter = 1;
        while (in.hasNext()) {
            if (n != 0) out.append('\n');
            out.append("Case ").append(caseCounter++).append(":\n");

            n = in.nextInt();

            for (int i = 1; i < n; ++i) picked[i] = false;

            findAndPrint(1);
        }
        System.out.print(out);
    }

    private static void findAndPrint(int level) {
        if (level == n && isPrime(circle[level - 1] + 1)) {
            out.append('1');
            for (int i = 1; i < n; ++i)
                out.append(' ').append(circle[i]);
            out.append('\n');
        } else for (int i = 1; i < n; ++i) {
            if (!picked[i] && isPrime(circle[level - 1] + i + 1)) {
                picked[i] = true;
                circle[level] = i + 1;
                findAndPrint(level + 1);
                picked[i] = false;
            }
        }
    }

    private static boolean isPrime(int number) {
        for (int prime: primes) {
            if (prime >= number) return true;
            if (number % prime == 0) return false;
        }
        return false;
    }
}

