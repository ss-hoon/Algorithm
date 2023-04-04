import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] world = new int[300][300];
    static int[][] melting = new int[300][300];
    static boolean[][] visited;
    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    static int N, M, land;

    static void dfs(int y, int x) {
        visited[y][x] = true;

        for (int idx=0; idx<4; idx++) {
            int Y = y + dy[idx];
            int X = x + dx[idx];

            if (Y < 0 || Y >= N || X < 0 || X >= M || world[Y][X] <= 0 || visited[Y][X]) continue;

            dfs(Y, X);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                world[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int seconds = 0;
        while (true) {
            visited = new boolean[N][M];

            // 1. 시간 증가
            seconds++;

            // 2. 육지 영역에서 얼마만큼 녹는지 계산
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    if (world[i][j] > 0) {
                        for (int k=0; k<4; k++) {
                            int Y = i + dy[k];
                            int X = j + dx[k];

                            if (Y < 0 || Y >= N || X < 0 || X >= M || world[Y][X] > 0) continue;

                            melting[i][j]++;
                        }
                    }
                }
            }

            // 3. 빙하를 녹인다.
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    if (melting[i][j] > 0) {
                        world[i][j] -= melting[i][j];
                        melting[i][j] = 0;
                    }
                }
            }

            // 4. 육지 부분 DFS해서 총 육지개수와 비교하여 다르면 break, 같으면 continue
            int cnt = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    if (world[i][j] > 0 && !visited[i][j]) {
                        dfs(i, j);
                        cnt++;
                    }
                }
            }

            if (cnt == 0) {
                seconds = 0;
                break;
            } else if (cnt >= 2) {
                break;
            }
        }

        System.out.println(seconds);
    }
}