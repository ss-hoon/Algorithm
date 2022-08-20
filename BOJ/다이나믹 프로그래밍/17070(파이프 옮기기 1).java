import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N;
    static char[][] house;
    static int[][][] cache; // 세로, 가로, 방향(0: 오른쪽, 1: 대각선, 2: 아래)
    static int[][] nextDir = { {0, 1}, {0, 1, 2}, {1, 2} };
    static int[][] dy = { {0, 1}, {0, 1, 1}, {1, 1} };
    static int[][] dx = { {1, 1}, {1, 1, 0}, {1, 0} };

    static int solve(int y, int x, int dir) {
        if(y == N-1 && x == N-1)    return 1;
        if(cache[y][x][dir] != -1)  return cache[y][x][dir];

        int result = 0;
        for(int idx=0; idx<dy[dir].length; idx++) {
            int Y = y + dy[dir][idx];
            int X = x + dx[dir][idx];

            if(Y < 0 || Y >= N || X < 0 || X >= N)  continue;
            if(house[Y][X] == '1' || (nextDir[dir][idx] == 1 && (house[Y-1][X] == '1' || house[Y][X-1] == '1')))  continue;

            result += solve(Y, X, nextDir[dir][idx]);
        }

        return cache[y][x][dir] = result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        house = new char[N][N];
        cache = new int[N][N][3];

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                Arrays.fill(cache[i][j], -1);
            }
        }

        for(int idx=0; idx<N; idx++) {
            house[idx] = br.readLine().replace(" ", "").toCharArray();
        }

        System.out.println(solve(0, 1, 0));
        br.close();
    }
}