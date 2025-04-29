import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] sum = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for (int idx=1; idx<=N; idx++) {
            sum[idx] = sum[idx-1] + Integer.parseInt(st.nextToken());
        }

        int left=1, right=1, count=0;
        while (right <= N) {
            if (sum[right] - sum[left-1] > M)         left++;
            else if (sum[right] - sum[left-1] < M)    right++;
            else {
                count++;
                right++;
            }
        }

        System.out.println(count);
    }
}
