import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int T = Integer.parseInt(line[0]);
        int W = Integer.parseInt(line[1]);
        int result = 0;

        int cache[][][] = new int[T+1][3][W+1];

        // i: 시간(초) - 1초부터
        // j: 현재 위치 - 1, 2
        // k: 움직인 횟수(최대 : W)
        for(int i=1; i<=T; i++) {
            int dropPlum = Integer.parseInt(br.readLine());

            for(int j=1; j<=2; j++) {
                int plum = (j == dropPlum ? 1 : 0);
                int anotherPos = (j == 1 ? 2 : 1);

                for(int k=0; k<=W; k++) {
                    if(i == 1 && j == 2 && k == 0)  continue;

                    if(k == 0)  cache[i][j][0] = cache[i-1][j][0] + plum;
                    else cache[i][j][k] = Math.max(cache[i-1][j][k], cache[i-1][anotherPos][k-1]) + plum;

                    if(i == T)  result = Math.max(result, cache[T][j][k]);
                }
            }
        }

        System.out.println(result);
    }
}