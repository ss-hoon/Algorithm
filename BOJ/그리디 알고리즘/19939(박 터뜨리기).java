import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);

        int result = -1;
        int min = (K * K + K) / 2;
        if(min <= N) {
            result = (N - min) % K == 0 ? K-1 : K;
        }

        System.out.println(result);
    }
}