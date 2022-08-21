import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    private static int[] dy = {-2, -1, 1, 2, 2, 1, -1, -2};
    private static int[] dx = {-1, -2, -2, -1, 1, 2, 2, 1};

    private static class Position {
        int y, x, time;

        Position(int y, int x, int time) {
            this.y = y;
            this.x = x;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int test = Integer.parseInt(br.readLine());

        while(test-- > 0) {
            Queue<Position> que = new LinkedList<>();
            int boardLength = Integer.parseInt(br.readLine());

            boolean[][] visit = new boolean[boardLength][boardLength];
            String[] start = br.readLine().split(" ");
            String[] end = br.readLine().split(" ");

            int endY = Integer.parseInt(end[0]);
            int endX = Integer.parseInt(end[1]);

            que.add(new Position(Integer.parseInt(start[0]), Integer.parseInt(start[1]), 0));

            while(!que.isEmpty()) {
                Position pos = que.poll();

                if(pos.y == endY && pos.x == endX) {
                    sb.append(pos.time).append("\n");
                    break;
                }

                for(int idx=0; idx<8; idx++) {
                    int Y = pos.y + dy[idx];
                    int X = pos.x + dx[idx];

                    if(Y < 0 || Y >= boardLength || X < 0 || X >= boardLength)  continue;
                    if(visit[Y][X]) continue;

                    visit[Y][X] = true;
                    que.add(new Position(Y, X, pos.time + 1));
                }
            }
        }

        System.out.println(sb);
        br.close();
    }
}