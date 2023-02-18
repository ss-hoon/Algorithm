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
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Integer>[] next = new LinkedList[K+1];
        int[] appliances = new int[K+1];
        boolean[] check = new boolean[K+1];
        for(int idx=1; idx<=K; idx++) {
            next[idx] = new LinkedList<>();
        }

        st = new StringTokenizer(br.readLine());
        for(int idx=1; idx<=K; idx++) {
            appliances[idx] = Integer.parseInt(st.nextToken());
            next[appliances[idx]].add(idx);
        }

        int order = 1;
        int result = 0;
        while(N > 0 && order <= K) {
            int target = appliances[order++];

            if(!check[target]) {
                check[target] = true;
                N--;
            }
            
            next[target].poll();
        }

        while(order <= K) {
            int target = appliances[order++];  // 현재 순서

            if(!check[target]) {
                int[] min = {0, 0}; // n번 플러그, 그 다음 위치
                for(int idx=1; idx<=K; idx++) {
                    if(check[idx]) {
                        if(next[idx].isEmpty() || min[1] < next[idx].peek()) {
                            min[0] = idx;
                            min[1] = next[idx].isEmpty() ? 101 : next[idx].peek();
                        }
                    }
                }

                check[min[0]] = false;
                check[target] = true;
                result++;
            }

            next[target].poll();
        }

        System.out.println(result);
    }
}