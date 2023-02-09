import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] count = new int[26];

    static boolean check() {
        return !(count[0] > 0 || count[2] > 0 || count[6] > 0 || count[19] > 0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        char[] str = br.readLine().toCharArray();
        st = new StringTokenizer(br.readLine());

        count[0] = Integer.parseInt(st.nextToken());
        count[2] = Integer.parseInt(st.nextToken());
        count[6] = Integer.parseInt(st.nextToken());
        count[19] = Integer.parseInt(st.nextToken());

        int result = 0;
        for(int idx=0; idx<P; idx++)
            count[str[idx] - 'A']--;

        if(check()) result++;

        for(int idx=0; idx<S-P; idx++) {
            count[str[idx] - 'A']++;
            count[str[idx+P] - 'A']--;

            if(check()) result++;
        }

        System.out.println(result);
    }
}