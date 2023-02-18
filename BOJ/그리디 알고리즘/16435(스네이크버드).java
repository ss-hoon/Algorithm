import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[] fruits = new int[10001];
        st = new StringTokenizer(br.readLine());
        for(int idx=0; idx<N; idx++) {
            fruits[Integer.parseInt(st.nextToken())]++;
        }

        for(int idx=1; idx<=10000; idx++) {
            if(L < idx) break;

            L += fruits[idx];
        }

        System.out.println(L);
    }
}