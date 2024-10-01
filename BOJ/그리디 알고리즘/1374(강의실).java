import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<int[]> lectures = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) return o1[1] - o2[1];
                return o1[0] - o2[0];
            }
        });
        PriorityQueue<Integer> endTime = new PriorityQueue<>();
        int N = Integer.parseInt(br.readLine());

        for (int idx=0; idx<N; idx++) {
            String[] line = br.readLine().split(" ");
            lectures.add(new int[]{Integer.parseInt(line[1]), Integer.parseInt(line[2])});
        }

        endTime.add(lectures.poll()[1]);
        while (!lectures.isEmpty()) {
            int fastEndTime = endTime.peek();
            int[] nextLecture = lectures.poll();

            if (nextLecture[0] >= fastEndTime)
                endTime.poll();

            endTime.add(nextLecture[1]);
        }

        System.out.println(endTime.size());
    }
}