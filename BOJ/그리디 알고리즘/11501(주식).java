import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int[] day = new int[N];
            for(int idx=0; idx<N; idx++)
                day[idx] = Integer.parseInt(st.nextToken());

            int maxValue = day[N-1];
            long result = 0;
            for(int idx=N-2; idx>=0; idx--) {
                if(maxValue >= day[idx]) {
                    result += (maxValue - day[idx]);
                } else {
                    maxValue = day[idx];
                }
            }

            System.out.println(result);
        }
    }
}