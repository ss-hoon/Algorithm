import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 끝에 1, 2, 3을 붙일 수 있는지 확인
        // 1 -> 1번째 전 1, 2, 3
        // 2 -> 2번째 전 2, 3
        // 3 => 3번째 전 3
        int[][] cache = new int[4][10001];
        for(int j=1; j<=10000; j++) {
            for(int i=1; i<=3; i++) {
                if(i == j)    cache[i][j] = 1;
                else if(i == 1)  cache[i][j] = cache[1][j-1] + cache[2][j-1] + cache[3][j-1];
                else if((j-2) > 0 && i == 2) cache[i][j] = cache[2][j-2] + cache[3][j-2];
                else if((j-3) > 0 && i == 3) cache[i][j] = cache[3][j-3];
            }
        }

        int test = Integer.parseInt(br.readLine());
        while(test-- > 0) {
            int num = Integer.parseInt(br.readLine());

            sb.append(cache[1][num] + cache[2][num] + cache[3][num]).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}