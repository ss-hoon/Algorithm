import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = Integer.MAX_VALUE;
        int N = Integer.parseInt(br.readLine());
        char[] ball = br.readLine().toCharArray();

        int cntRedBall = 0, cntBlueBall = 0;
        for(int idx=0; idx<N; idx++) {
            if(ball[idx] == 'R')    cntRedBall++;
            else cntBlueBall++;
        }

        char firstBall = ball[0];
        char lastBall = ball[N-1];
        boolean flag = false;
        int cnt = 0;

        for(int idx=1; idx<N; idx++) {
            if(!flag && firstBall != ball[idx]) flag = true;
            if(flag && firstBall == ball[idx])  cnt++;
        }

        result = Math.min(result, Math.min(cnt, firstBall == 'R' ? cntBlueBall : cntRedBall));

        flag = false;
        cnt = 0;
        for(int idx=N-2; idx>=0; idx--) {
            if(!flag && lastBall != ball[idx]) flag = true;
            if(flag && lastBall == ball[idx])  cnt++;
        }

        result = Math.min(result, Math.min(cnt, lastBall == 'R' ? cntBlueBall : cntRedBall));

        System.out.println(result);
    }
}