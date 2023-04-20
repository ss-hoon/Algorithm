import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int R = Integer.parseInt(line[0]);
        int C = Integer.parseInt(line[1]);
        int type = 0;
        int[] dy = {0, 1, 0, -1};
        int[] dx = {1, 0, -1, 0};
        int[][] board = new int[R+1][C+1];

        int K = Integer.parseInt(br.readLine());
        if (R*C < K) {
            System.out.println("0");
        } else {
            int num = 1;
            int y = 1, x = 1;
            while (true) {
                if (num == K) {
                    System.out.println(y + " " + x);
                    break;
                }

                board[y][x] = num++;
                int nextY = y + dy[type];
                int nextX = x + dx[type];

                if (nextY <= 0 || nextY > R || nextX <= 0 || nextX > C || board[nextY][nextX] != 0) {
                    type = (type + 1) % 4;
                    y += dy[type];
                    x += dx[type];
                    continue;
                }

                y = nextY;
                x = nextX;
            }
        }
    }
}