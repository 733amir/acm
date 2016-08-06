import java.util.Scanner;

public class Main {
    private static int s, d, maximum;
    private static int[] months = new int[12];
    private static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        while (in.hasNext()) {
            s = in.nextInt();
            d = in.nextInt();

            maximum = Integer.MIN_VALUE;
            select(0);

            System.out.println(maximum < 0? "Deficit": maximum);
        }
    }

    private static void select(int i) {
        if (i > 4)
            for (int j = 0; j < i - 4; ++j)
                if (months[j] + months[j + 1] + months[j + 2] + months[j + 3] + months[j + 4] > -1)
                    return;

        if (i == 12) {
            int total = 0;
            for (int j = 0; j < 12; ++j)
                total += months[j];
            if (total > maximum)
                maximum = total;
            return;
        }

        months[i] = s;
        select(i + 1);

        months[i] = -d;
        select(i + 1);
    }
}

