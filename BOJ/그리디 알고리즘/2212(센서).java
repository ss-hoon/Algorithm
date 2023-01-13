import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        int[] list = new int[N];
        int[] dist = new int[N-1];
        int result = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int idx=0; idx<N; idx++)
            list[idx] = Integer.parseInt(st.nextToken());

        Arrays.sort(list);
        for(int idx=0; idx<N-1; idx++)
            dist[idx] = (list[idx+1] - list[idx]);

        Arrays.sort(dist);
        for(int idx=0; idx<N-K; idx++)
            result += dist[idx];

        System.out.println(result);
    }
}