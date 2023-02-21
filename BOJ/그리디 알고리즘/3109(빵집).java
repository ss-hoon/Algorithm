import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static char[][] board = new char[10001][501];
    static int[] dy = {-1, 0, 1};
    static int R, C;

    static boolean dfs(int y, int x) {
        if(x == C-1) return true;

        for(int idx=0; idx<3; idx++) {
            int nextY = y + dy[idx];
            int nextX = x + 1;

            if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C || board[nextY][nextX] == 'x')   continue;

            board[nextY][nextX] = 'x';
            if(dfs(nextY, nextX)) return true;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        for(int idx=0; idx<R; idx++)
            board[idx] = br.readLine().toCharArray();

        int result = 0;
        for(int idx=0; idx<R; idx++) {
            if(dfs(idx, 0)) result++;
        }

        System.out.println(result);
    }
}