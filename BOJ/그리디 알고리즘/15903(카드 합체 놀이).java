import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        PriorityQueue<Long> cards = new PriorityQueue<>();

        while(st.hasMoreTokens())
            cards.add(Long.parseLong(st.nextToken()));

        while(m-- > 0) {
            long c1 = cards.poll();
            long c2 = cards.poll();

            cards.add(c1 + c2);
            cards.add(c1 + c2);
        }

        long result = 0;
        while(!cards.isEmpty())
            result += cards.poll();

        System.out.println(result);
    }
}