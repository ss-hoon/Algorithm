import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Queue<Integer> que = new LinkedList<>();

        int N = Integer.parseInt(st.nextToken());
        N += Integer.parseInt(st.nextToken());
        int[] bridge = new int[101];
        int[] cnt = new int[101];

        for (int idx=1; idx<=100; idx++) {
            bridge[idx] = idx;
        }

        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            bridge[x] = y;
        }

        que.add(1);
        cnt[1] = 0;
        while (!que.isEmpty()) {
            int current = que.poll();

            for (int idx=1; idx<=6; idx++) {
                if (current + idx > 100 || cnt[bridge[current + idx]] > 0)    continue;
                int next = bridge[current + idx];

                if (next == 100) {
                    System.out.println(cnt[current] + 1);
                    return;
                }
                
                cnt[next] = cnt[current] + 1;
                que.add(next);
            }
        }
    }
}