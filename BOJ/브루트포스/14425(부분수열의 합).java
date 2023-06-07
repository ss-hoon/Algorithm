import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int idx=0; idx<N; idx++)
            arr[idx] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);

        int result = 0;
        for (int idx=0; idx<N; idx++) {
            if (result + 1 < arr[idx])  break;

            result += arr[idx];
        }

        System.out.println(result + 1);
    }
}