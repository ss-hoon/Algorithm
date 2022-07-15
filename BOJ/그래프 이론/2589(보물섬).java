import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int row, col;                // 보물지도 세로, 가로
    private static int result;                  // 보물의 최단 거리
    private static char[][] map;                // 보물 지도
    private static int[] dy = {-1, 1, 0, 0};    // 상.하.좌.우 y 값
    private static int[] dx = {0, 0, -1, 1};    // 상.하.좌.우 x 값
    
    /* 큐에 넣을 Point 객체 */
    private static class Point {
        int y, x, cnt;

        Point(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
    
    /* BFS */
    private static void bfs(int y, int x) {
        Queue<Point> que = new LinkedList<>();
        boolean[][] visit = new boolean[row][col];

        que.add(new Point(y, x, 0));
        while(!que.isEmpty()) {
            Point front = que.poll();
            visit[front.y][front.x] = true;
            result = Math.max(result, front.cnt);

            for(int idx=0; idx<4; idx++) {
                int ny = front.y + dy[idx];
                int nx = front.x + dx[idx];

                if(!isValidPoint(ny, nx))  continue;
                if(map[ny][nx] == 'W' || visit[ny][nx])    continue;

                visit[ny][nx] = true;
                que.add(new Point(ny, nx, front.cnt + 1));
            }
        }
    }
    
    /* 시작점 조회 */
    // 현재 위치가 중간 위치라면 그 지점은 시작점이 아니다.
    // o + o    => + 위치는 어떻게 해도 최단 거리가 아님
    private static boolean isStartPoint(int y, int x) {
        int hcount = 0, wcount = 0, count = 0;

        for(int idx=0; idx<4; idx++) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];

            if(!isValidPoint(ny, nx))   continue;
            if(map[ny][nx] == 'L'){
                count++;
                if(idx == 0 || idx == 1) hcount++;
                else wcount++;
            }
        }

        return count == 1 || (count == 2 && wcount == 1 && hcount == 1);
    }
    
    /* 보물지도 유효 범위 조회 */
    private static boolean isValidPoint(int y, int x) {
        return y >= 0 && y < row && x >= 0 && x < col;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());

        map = new char[row][col];
        for(int i=0; i<row; i++)
            map[i] = br.readLine().toCharArray();

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(map[i][j] == 'L' && isStartPoint(i, j))
                    bfs(i, j);
            }
        }

        System.out.println(result);
    }
}