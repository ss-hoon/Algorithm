import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] health = new int[N+1];
        int[] happy = new int[N+1];
        int[][] cache = new int[N+1][100];

        st = new StringTokenizer(br.readLine());
        for (int idx=1; idx<=N; idx++) {
            health[idx] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int idx=1; idx<=N; idx++) {
            happy[idx] = Integer.parseInt(st.nextToken());
        }

        for (int i=1; i<=N; i++) {
            for (int j=1; j<100; j++) {
                if (j < health[i])  cache[i][j] = cache[i-1][j];
                else cache[i][j] = Math.max(cache[i-1][j-health[i]] + happy[i], cache[i-1][j]);
            }
        }

        System.out.println(cache[N][99]);
    }
}