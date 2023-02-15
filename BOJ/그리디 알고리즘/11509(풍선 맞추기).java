import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        int[] check = new int[1000002];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int idx=0; idx<N; idx++) {
            int balloon = Integer.parseInt(st.nextToken());

            if(check[balloon+1] == 0) {
                check[balloon]++;
                result++;
            } else {
                check[balloon+1]--;
                check[balloon]++;
            }
        }

        System.out.println(result);
    }
}