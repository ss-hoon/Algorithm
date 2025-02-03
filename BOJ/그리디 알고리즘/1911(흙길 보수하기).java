import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int[][] road = new int[N][2];

        for (int idx=0; idx<N; idx++) {
            st = new StringTokenizer(br.readLine());
            road[idx][0] = Integer.parseInt(st.nextToken());
            road[idx][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(road, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        int result = 0;
        int start = 0;
        for (int idx=0; idx<N; idx++) {
            if (road[idx][1] < start)
                continue;

            if (start < road[idx][0])
                start = road[idx][0];

            if ((road[idx][1] - start) % L == 0) {
                result += ((road[idx][1] - start) / L);
                start += L * (((road[idx][1] - start) / L));
            } else {
                result += ((road[idx][1] - start) / L) + 1;
                start += L * (((road[idx][1] - start) / L) + 1);
            }
        }

        System.out.println(result);
    }
}
