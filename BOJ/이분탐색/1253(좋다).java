import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] numList = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int idx=0; idx<N; idx++)
            numList[idx] = Integer.parseInt(st.nextToken());

        Arrays.sort(numList);

        int result = 0;
        for(int select=0; select<N; select++) {
            int left = 0;
            int right = N-1;

            while(left < right) {
                if(left == select)  left++;
                if(right == select) right--;
                if(left == right)   break;

                int sum = numList[left] + numList[right];

                if(sum == numList[select]) {
                    result++;
                    break;
                }

                else if(sum > numList[select]) right--;
                else left++;
            }
        }

        System.out.println(result);
        br.close();
    }
}