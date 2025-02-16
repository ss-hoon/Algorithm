import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int D = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);

        int[][] cache = new int[2][D+1];
        cache[0][1] = 1; cache[0][2] = 0;
        cache[1][1] = 0; cache[1][2] = 1;

        for (int i=3; i<=D; i++) {
            cache[0][i] = cache[0][i-1] + cache[0][i-2];
            cache[1][i] = cache[1][i-1] + cache[1][i-2];
        }

        int a = cache[0][D];
        int b = cache[1][D];

        for (long i=1;a*i<K;i++) {
            for (long j=i; a*i+b*j<=K; j++) {
                if (a*i+b*j==K) {
                    System.out.println(i + "\n" + j);
                    return;
                }
            }
        }
    }
}
