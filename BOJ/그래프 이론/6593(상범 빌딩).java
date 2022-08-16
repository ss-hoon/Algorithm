import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int[] dx = {0, 0, 0, -1, 1, 0};
    private static int[] dy = {0, 0, -1, 0, 0, 1};
    private static int[] dz = {-1, 1, 0, 0, 0, 0};

    private static class Position {
        int x, y, z, time;

        Position(int z, int y, int x, int time) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            if(L == 0 && R == 0 && C == 0)  break;

            char[][][] building = new char[L][R][C];
            Queue<Position> que = new LinkedList<>();

            for(int i=0; i<L; i++) {
                for(int j=0; j<R; j++) {
                    char[] line = br.readLine().toCharArray();
                    for(int k=0; k<C; k++) {
                        building[i][j][k] = line[k];
                        if(line[k] == 'S')  que.add(new Position(i, j, k, 0));
                    }
                }

                br.readLine();
            }

            int result = 0;
            while(!que.isEmpty()) {
                Position p = que.poll();

                if(building[p.z][p.y][p.x] == 'E') {
                    result = p.time;
                    break;
                }

                for(int idx=0; idx<6; idx++) {
                    int X = p.x + dx[idx];
                    int Y = p.y + dy[idx];
                    int Z = p.z + dz[idx];

                    if(X < 0 || X >= C || Y < 0 || Y >= R || Z < 0 || Z >= L)  continue;
                    if(building[Z][Y][X] == '#')    continue;

                    if(building[Z][Y][X] == '.')    building[Z][Y][X] = '#';
                    que.add(new Position(Z, Y, X, p.time + 1));
                }
            }

            if(result > 0)
                sb.append("Escaped in ").append(result).append(" minute(s).").append("\n");
            else
                sb.append("Trapped!").append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}