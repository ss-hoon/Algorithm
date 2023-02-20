import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Position {
        int y, x, dist, broke;

        Position(int y, int x, int dist, int broke) {
            this.y = y;
            this.x = x;
            this.dist = dist;
            this.broke = broke;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        QueuePosition que = new LinkedList();

        int[] dy = {-1, 0, 0, 1};
        int[] dx = {0, -1, 1, 0};

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        char[][] board = new char[N][M];
        boolean[][][] visited = new boolean[N][M][2];

        for(int idx=0; idxN; idx++) {
            board[idx] = br.readLine().toCharArray();
        }

        visited[0][0][0] = true;
        que.offer(new Position(0, 0, 1, 0));

        int result = -1;
        while(!que.isEmpty()) {
            Position p = que.poll();

            if(p.y == N-1 && p.x == M-1) {
                result = p.dist;
                break;
            }

            for(int idx=0; idx4; idx++) {
                int nextY = p.y + dy[idx];
                int nextX = p.x + dx[idx];
                int dist = p.dist + 1;
                int broke = p.broke;

                if(nextY  0  nextY = N  nextX  0  nextX = M)  continue;

                int nextStatus = broke + (board[nextY][nextX] - '0');
                if(nextStatus == 2  visited[nextY][nextX][nextStatus])    continue;

                visited[nextY][nextX][nextStatus] = true;
                que.offer(new Position(nextY, nextX, dist, nextStatus));
            }
        }

        System.out.println(result);
    }
}