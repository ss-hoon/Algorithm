import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] input = new int[N];
        int[] diff = new int[N-1];
        st = new StringTokenizer(br.readLine());

        input[0] = Integer.parseInt(st.nextToken());
        for(int idx=1; idxN; idx++) {
            input[idx] = Integer.parseInt(st.nextToken());
            diff[idx-1] = input[idx] - input[idx-1];
        }

        Arrays.sort(diff);

        int result = 0;
        for(int idx=0; idxN-K; idx++) {
            result += diff[idx];
        }

        System.out.println(result);
    }
}