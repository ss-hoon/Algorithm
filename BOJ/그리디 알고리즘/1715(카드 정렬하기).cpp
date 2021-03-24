import java.io.*;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int sum = 0;
        int N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            pq.add(Integer.parseInt(br.readLine()));
        }

        // 우선순위 큐에서 작은 수 두개를 연산 (Greedy 방식)
        // 1개 남을때까지 반복
        while(pq.size() != 1){
            int a = pq.poll();
            int b = pq.poll();

            sum += a + b;
            pq.add(a + b);
        }

        System.out.println(sum);
    }
}