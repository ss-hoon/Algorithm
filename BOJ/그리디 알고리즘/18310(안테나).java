import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] house = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int idx=0; idx<N; idx++)
            house[idx] = Integer.parseInt(st.nextToken());

        Arrays.sort(house);
        System.out.println(N % 2 == 0 ? house[N/2-1] : house[N/2]);
    }
}