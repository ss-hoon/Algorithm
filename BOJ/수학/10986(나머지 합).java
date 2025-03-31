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
        long[] modular = new long[M];
        int remain = 0;

        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            remain += (Integer.parseInt(st.nextToken()) % M);
            modular[remain % M]++;
        }

        long result = modular[0];
        for (int idx=0; idx<M; idx++)
            result += modular[idx] * (modular[idx]-1) / 2;

        System.out.println(result);
    }
}
