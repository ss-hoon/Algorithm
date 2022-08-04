import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dz = {-1, 0, 0, 0, 0, 1};
    static int[] dy = {0, -1, 0, 0, 1, 0};
    static int[] dx = {0, 0, -1, 1, 0, 0};
    static int[][][] warehouse;
    static int N, M, H, allUnripeTomato;
    static Queue<Position> que = new LinkedList<>();

    static class Position {
        int x, y, z, time;

        Position(int z, int y, int x, int time) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.time = time;
        }
    }

    static int getAllRipeTime() {
        int result = 0;
        int cntRipeTomato = 0;

        while(!que.isEmpty()) {
            Position pos = que.poll();

            if(pos.time > result)   result = pos.time;
            for(int idx=0; idx<6; idx++) {
                int X = pos.x + dx[idx];
                int Y = pos.y + dy[idx];
                int Z = pos.z + dz[idx];

                if(X < 0 || X >= M || Y < 0 || Y >= N || Z < 0 || Z >= H || warehouse[Z][Y][X] != 0)   continue;

                warehouse[Z][Y][X] = 1;
                cntRipeTomato++;
                que.add(new Position(Z, Y, X, pos.time+1));
            }
        }

        return cntRipeTomato == allUnripeTomato ? result : -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        warehouse = new int[H][N][M];

        for(int i=0; i<H; i++) {
            for(int j=0; j<N; j++) {
                st = new StringTokenizer(br.readLine());

                for(int k=0; k<M; k++) {
                    int tomato = Integer.parseInt(st.nextToken());
                    warehouse[i][j][k] = tomato;

                    if(tomato == 0)
                        allUnripeTomato++;
                    else if(tomato == 1)
                        que.add(new Position(i, j, k, 0));
                }
            }
        }

        System.out.println(getAllRipeTime());
        br.close();
    }
}