import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] solution = new int[N];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int idx=0; idx<N; idx++) {
            solution[idx] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(solution);

        int left = 0;
        int right = N-1;
        int[] result = { Integer.MAX_VALUE, 0, 0 };
        while (left < right) {
            int sum = solution[left] + solution[right];

            if (Math.abs(sum) < result[0]) {
                result[0] = Math.abs(sum);
                result[1] = solution[left];
                result[2] = solution[right];
            }

            if (sum < 0) left++;
            else if(sum > 0)   right--;
            else break;
        }

        System.out.println(result[1] + " " + result[2]);
    }
}