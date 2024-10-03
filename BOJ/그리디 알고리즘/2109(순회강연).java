import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    private static int[] days = new int[10001];
    private static int getParent(int idx) {
        if (days[idx] == idx)   return idx;
        return days[idx] = getParent(days[idx]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });
        int result = 0;

        for (int idx=1; idx<10001; idx++)
            days[idx] = idx;

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] line = br.readLine().split(" ");
            pq.add(new int[]{ Integer.parseInt(line[0]), Integer.parseInt(line[1]) });
        }

        while (!pq.isEmpty()) {
            int[] top = pq.poll();

            int findDays = getParent(top[1]);
            if (findDays != 0) {
                result += top[0];
                days[findDays]--;
            }
        }

        System.out.println(result);
    }
}