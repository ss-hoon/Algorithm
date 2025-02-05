import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            char[] str = br.readLine().toCharArray();
            int result = getResult(str, 0, str.length-1, 0);
            sb.append(Math.min(2, result)).append('\n');
        }

        System.out.println(sb);
    }

    private static int getResult(char[] str, int leftIdx, int rightIdx, int cnt) {
        if (leftIdx >= rightIdx)    return 0;
        if (cnt >= 2)   return 2;

        char left = str[leftIdx];
        char right = str[rightIdx];

        if (left == right) {
            return getResult(str, leftIdx+1, rightIdx-1, cnt);
        } else {
            return Math.min(getResult(str, leftIdx+1, rightIdx, cnt+1), getResult(str, leftIdx, rightIdx-1, cnt+1)) + 1;
        }
    }
}
