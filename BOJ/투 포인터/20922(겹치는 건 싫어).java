import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] sequence = new int[N];
        int[] cnt = new int[100001];
        st = new StringTokenizer(br.readLine());

        for(int idx=0; idx<N; idx++)
            sequence[idx] = Integer.parseInt(st.nextToken());

        int left = 0;
        int right = 0;
        int result = 0;

        // 투포인터 알고리즘
        // right를 증가시키다가 
        // right에 해당하는 부분이 K값을 넘어갈 때,
        // left를 증가
        while(right < N) {
            int leftNum = sequence[left];
            int rightNum = sequence[right];

            if(cnt[rightNum] + 1 <= K) {
                cnt[rightNum]++;
                right++;
            } else {
                cnt[leftNum]--;
                left++;
            }

            result = Math.max(result, right - left);
        }

        System.out.println(result);
        br.close();
    }
}