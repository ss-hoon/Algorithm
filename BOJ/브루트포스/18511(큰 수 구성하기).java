import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int N, K;
    private static final int[] elements = new int[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int idx = 0;
        while (st.hasMoreElements()) {
            elements[idx++] = Integer.parseInt(st.nextToken());
        }

        System.out.println(getMaxNumber(0, 0));
    }

    private static int getMaxNumber(int num, int digit) {
        if (num > N)    return 0;
        int result = num;

        for (int idx=0; idx<K; idx++) {
            result = Math.max(result, getMaxNumber(num + elements[idx] * (int) Math.pow(10, digit), digit+1));
        }

        return result;
    }
}
