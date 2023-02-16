import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][] flowers = new int[N][2];
        for(int idx=0; idx<N; idx++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            flowers[idx][0] = Integer.parseInt(st.nextToken()) * 100 + Integer.parseInt(st.nextToken());
            flowers[idx][1] = Integer.parseInt(st.nextToken()) * 100 + Integer.parseInt(st.nextToken());

            flowers[idx][0] = Math.max(301, flowers[idx][0]);
            flowers[idx][1] = Math.min(1201, flowers[idx][1]);
        }

        Arrays.sort(flowers, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                } else {
                    return o1[0] - o2[0];
                }
            }
        });

        int result = 0;
        int[] check = {300, 301};
        for(int idx=0; idx<N; idx++) {
            if(check[0] == flowers[idx][0]) {
                check[1] = flowers[idx][1];
            } else if(flowers[idx][1] < check[1]) {
                continue;
            } else if(check[1] < flowers[idx][0]) {
                break;
            } else {
                result++;
                int maxEndDay = check[1];
                while(idx < N && flowers[idx][0] <= check[1]) {
                    maxEndDay = Math.max(maxEndDay, flowers[idx++][1]);
                }

                check[1] = maxEndDay;
                idx--;
                if(check[1] == 1201)    break;
            }
        }

        System.out.println(check[1] == 1201 ? result : 0);
    }
}