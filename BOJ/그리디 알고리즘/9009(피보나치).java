import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] fibonacci = new int[45];
        fibonacci[1] = 1;
        for(int idx=2; idx<45; idx++) {
            fibonacci[idx] = fibonacci[idx-1] + fibonacci[idx-2];
        }

        StringBuilder answer = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            StringBuilder sb = new StringBuilder();
            int n = Integer.parseInt(br.readLine());
            for(int idx=44; idx>=0; idx--) {
                if(n < fibonacci[idx]) continue;
                if(n <= 0) break;

                n -= fibonacci[idx];
                sb.insert(0, fibonacci[idx] + " ");
            }

            answer.append(sb).append("\n");
        }

        System.out.println(answer);
    }
}