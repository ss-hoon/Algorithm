import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, String> dict = new HashMap<>();
        while(N-- > 0) {
            st = new StringTokenizer(br.readLine());

            String site = st.nextToken();
            String pwd = st.nextToken();

            dict.put(site, pwd);
        }

        StringBuilder sb = new StringBuilder();
        while(M-- > 0) {
            st = new StringTokenizer(br.readLine());

            String site = st.nextToken();
            sb.append(dict.get(site)).append('\n');
        }

        System.out.println(sb);
    }
}