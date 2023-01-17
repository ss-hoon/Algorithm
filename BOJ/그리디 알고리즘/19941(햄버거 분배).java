import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static char[] line;

    static boolean isEatHamburger(int pivot) {
        int start = pivot-K < 0 ? 0 : pivot-K;
        int end = pivot+K > N-1 ? N-1 : pivot+K;

        for(int idx=start; idx<=end; idx++) {
            if(line[idx] == 'H') {
                line[idx] = 'E';
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int result = 0;
        line = br.readLine().toCharArray();
        for(int idx=0; idx<N; idx++) {
            if(line[idx] == 'P' && isEatHamburger(idx)) {
                result++;
            }
        }

        System.out.println(result);
    }
}