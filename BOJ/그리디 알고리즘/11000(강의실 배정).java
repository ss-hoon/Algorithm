import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][2];
        for(int idx=0; idx<N; idx++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[idx][0] = Integer.parseInt(st.nextToken());
            arr[idx][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        pq.add(arr[0][1]);
        for(int idx=1; idx<N; idx++) {
            if(pq.peek() <= arr[idx][0])
                pq.poll();

            pq.add(arr[idx][1]);
        }

        System.out.println(pq.size());
    }
}