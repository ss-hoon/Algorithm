import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            sb.append(st.nextToken());
            for (int idx=1; idx<N; idx++) {
                int next = st.nextToken().charAt(0);

                if (sb.charAt(0) < next) sb.append((char) next);
                else sb.insert(0, (char) next);
            }

            System.out.println(sb);
        }
    }
}