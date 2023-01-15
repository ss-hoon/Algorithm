import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long N = Long.parseLong(st.nextToken());
        long M = Long.parseLong(st.nextToken());

        long result = 0;
        if(N == 1) {
            result = 1;
        } else if(N == 2) {
            result = Math.min(4, (M+1)/2);
        } else {
            if (M >= 7) {
                result = M - 2;
            } else {
                result = Math.min(4, M);
            }
        }

        System.out.println(result);
    }
}