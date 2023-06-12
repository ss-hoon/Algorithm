import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] cache = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int idx=0; idx<N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (arr[i] < arr[j] && cache[i] < cache[j])
                    cache[i] = cache[j];
            }

            cache[i] += arr[i];
        }

        int sum = 0;
        for (int idx=0; idx<N; idx++)
            sum = Math.max(sum, cache[idx]);

        System.out.println(sum);
    }
}
