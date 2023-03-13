import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            PriorityQueue<Long> pq = new PriorityQueue<>();
            br.readLine();
            String[] line = br.readLine().split(" ");

            for (int idx=0; idx<line.length; idx++) {
                pq.add(Long.parseLong(line[idx]));
            }

            long result = 0;
            while (pq.size() > 1) {
                long sum = pq.poll() + pq.poll();

                pq.add(sum);
                result += sum;
            }

            sb.append(result).append('\n');
        }

        System.out.println(sb);
    }
}