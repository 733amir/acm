import java.util.*;

public class Main {
    private static Scanner in = new Scanner(System.in);
    private static Map<Character, List<Integer>> data = new HashMap<>();
    private static Map<Character, Integer> index = new HashMap<>();
    private static String s, ss;
    private static int queryCount, start, max, cur;

    public static void main(String[] args) {
        data.clear();
        s = in.next();

        List<Integer> places;
        for (int i = 0; i < s.length(); ++i) {
            places = data.getOrDefault(s.charAt(i), new ArrayList<>(1000));
            places.add(i);
            data.put(s.charAt(i), places);
        }

        start = max = -1;

        queryCount = in.nextInt();

        while (queryCount-- != 0) {
            ss = in.next();

            int i;
            for (i = 0; i < ss.length(); ++i)
                index.put(ss.charAt(i), 0);

            for (i = 0; i < ss.length(); ++i) {
                places = data.getOrDefault(ss.charAt(i), null);
                if (places == null || places.isEmpty()) break;
                else if (i == 0) {
                    start = max = places.get(index.get(ss.charAt(i)));
                    index.put(ss.charAt(i), index.get(ss.charAt(i)) + 1);
                } else {
                    cur = -1;
                    while (index.get(ss.charAt(i)) < places.size() && cur <= max) {
                        cur = places.get(index.get(ss.charAt(i)));
                        index.put(ss.charAt(i), index.get(ss.charAt(i)) + 1);
                    }
                    if (cur <= max)
                        break;
                    else
                        max = cur;
                }
            }

            if (i != ss.length()) {
                System.out.println("Not matched");
            } else {
                System.out.println("Matched " + start + " " + max);
            }
        }
    }
}
