import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger[][] cache = new BigInteger[101][101];

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i=1; i<=n; i++) {
            for (int j=0; j<=i; j++) {
                if (j==0 || j==i)   cache[i][j] = BigInteger.ONE;
                else cache[i][j] = cache[i-1][j-1].add(cache[i-1][j]);
            }
        }

        System.out.println(cache[n][m]);
    }
}
