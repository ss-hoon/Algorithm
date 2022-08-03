import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, M, W, B;
    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    static boolean[][] visit;
    static char[][] board;

    static int dfs(int y, int x, int team) {
        if (y < 0 || y >= N || x < 0 || x >= M)  return 0;
        if(visit[y][x] || team != board[y][x]) return 0;

        visit[y][x] = true;
        int sum = 1;

        for(int idx=0; idx<4; idx++) {
            int Y = y + dy[idx];
            int X = x + dx[idx];

            sum += dfs(Y, X, team);
        }

        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        M = Integer.parseInt(line[0]);
        N = Integer.parseInt(line[1]);
        visit = new boolean[N][M];
        board = new char[N][M];

        for(int i=0; i<N; i++)
            board[i] = br.readLine().toCharArray();

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j] == 'W')
                    W += Math.pow(dfs(i, j, 'W'), 2);
                else
                    B += Math.pow(dfs(i, j, 'B'), 2);
            }
        }

        System.out.println(W + " " + B);
    }
}