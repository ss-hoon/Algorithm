import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int cnt = Integer.parseInt(st.nextToken()); // 동전 개수
        int goal = Integer.parseInt(st.nextToken()); // 목표치
        int[] coin = new int[cnt]; // 코인 배열 할당
        int[][] cache = new int[cnt][goal+1]; // 캐시 배열 할당

        for(int index = 0; index < cnt; index++)    coin[index] = Integer.parseInt(br.readLine());

        for(int i = 0; i < cnt; i++){
            for(int j = 1; j < goal+1; j++){
                if(i == 0) { // 맨 처음일 경우에는 나누어 떨어지면 나눈값을, 나누어 떨어지지 않으면 -1을 캐시 배열에 작성한다
                    if(j % coin[i] == 0)    cache[i][j] = j / coin[i];
                    else cache[i][j] = -1;
                }
                else { // 맨 처음이 아닌 경우
                    if (j < coin[i]) cache[i][j] = cache[i-1][j]; // 현재 비교하는 동전 가치가 현재 목표치(j값)보다 높을 경우에는 거슬러줄 수 없기 때문에 위의 캐시 배열 값을 그대로 가져온다
                    else { // 현재 비교하는 동전 가치가 현재 목표치(j값)보다 낮을 경우
                        if (cache[i - 1][j] == -1 && cache[i][j - coin[i]] == -1) cache[i][j] = -1; // 전에 비교했던 동전으로도 거슬러줄 수 없고, 현재 비교하는 동전으로도 거슬러 줄 수 없을 때
                        else if (cache[i - 1][j] == -1) cache[i][j] = cache[i][j - coin[i]] + 1; // 현재 비교하는 동전으로 거슬러줄 수 있을 때
                        else if (cache[i][j - coin[i]] == -1) cache[i][j] = cache[i - 1][j]; // 전에 비교했던 동전으로만 거슬러줄 수 있을 때
                        else cache[i][j] = Math.min(cache[i - 1][j], cache[i][j - coin[i]] + 1); // 둘다 가능할 때
                    }
                }
            }
        }
        System.out.println(cache[cnt-1][goal]);
    }
}