import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Position implements Comparable<Position> {
        int y, x, dir, mirror; // dir(0: 상, 1: 하, 2: 좌, 3: 우)

        Position(int y, int x, int dir, int mirror) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.mirror = mirror;
        }

        @Override
        public int compareTo(Position p) {
            return this.mirror - p.mirror;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Position> pq = new PriorityQueue<>();
        int[] dy = {-1, 1, 0, 0};
        int[] dx = {0, 0, -1, 1};

        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());

        int[][] map = new int[H][W];
        int[] endPoint = new int[4];
        int[][][] visit = new int[H][W][4];
        int idx = 0;

        for(int i=0; i<H; i++) {
            st = new StringTokenizer(br.readLine());
            char[] token = st.nextToken().toCharArray();
            for(int j=0; j<W; j++) {
                map[i][j] = token[j];
                for(int k=0; k<4; k++)
                    visit[i][j][k] = Integer.MAX_VALUE;

                if(token[j] == 'C') {
                    endPoint[idx++] = i;
                    endPoint[idx++] = j;
                }
            }
        }

        for(int it=0; it<4; it++) {
            pq.add(new Position(endPoint[0], endPoint[1], it, 0));
            visit[endPoint[0]][endPoint[1]][it] = 0;
        }

        while(!pq.isEmpty()) {
            Position pos = pq.poll();

            if(pos.y == endPoint[2] && pos.x == endPoint[3]) {
                System.out.println(pos.mirror);
                break;
            }

            for(int it=0; it<4; it++) {
                int Y = pos.y + dy[it];
                int X = pos.x + dx[it];

                if(Y < 0 || Y >= H || X < 0 || X >= W || map[Y][X] == '*')  continue;

                if(it == pos.dir && visit[Y][X][it] > pos.mirror) {
                    visit[Y][X][it] = pos.mirror;
                    pq.add(new Position(Y, X, it, pos.mirror));
                }

                if(it != pos.dir && visit[Y][X][it] > pos.mirror+1) {
                    visit[Y][X][it] = pos.mirror+1;
                    pq.add(new Position(Y, X, it, pos.mirror+1));
                }
            }
        }

        br.close();
    }
}