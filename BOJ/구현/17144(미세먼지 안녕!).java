import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] board;
    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    static int[] cw = {3, 2, 0, 1};
    static int[] ccw = {0, 2, 3, 1};
    static int[] airCleanerY = {-1, -1};
    static int R, C, T;

    static boolean outOfRange(int y, int x){
        if(y < 0 || y >= R || x < 0 || x >= C)  return true;
        return false;
    }

    // 입력
    static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        board = new int[R][C];

        for(int i=0;i<R;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<C;j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j] == -1 && airCleanerY[0] == -1){
                    airCleanerY[0] = i;
                    airCleanerY[1] = i+1;
                }
            }
        }
    }

    // 먼지 퍼트리기
    static void spreadDust(){
        int[][] changeBoard = new int[R][C];

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++) {
                if(board[i][j] < 5) changeBoard[i][j] += board[i][j];
                else {
                    int cnt = 0;
                    int give = board[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];

                        if (outOfRange(y, x)) continue;
                        if (board[y][x] == -1) continue;

                        changeBoard[y][x] += give;
                        cnt++;
                    }
                    changeBoard[i][j] += board[i][j] - give * cnt;
                }
            }
        }
        board = changeBoard;
    }

    // 공기청정기 위쪽 바람
    static void upAirCleaner(){
        int y = airCleanerY[0];
        int x = 0;
        for(int k=0;k<4;k++){
            while(true){
                int ny = y + dy[ccw[k]];
                int nx = x + dx[ccw[k]];

                if(outOfRange(ny, nx))  break;
                if(ny > airCleanerY[0]) break;
                if(ny == airCleanerY[0] && nx == 0) break;

                board[y][x] = board[ny][nx];
                y = ny;
                x = nx;
            }
        }
        board[y][0] = -1;
        board[y][1] = 0;
    }

    // 공기청정기 아래쪽 바람
    static void downAirCleaner(){
        int y = airCleanerY[1];
        int x = 0;
        for(int k=0;k<4;k++){
            while(true){
                int ny = y + dy[cw[k]];
                int nx = x + dx[cw[k]];

                if(outOfRange(ny, nx))  break;
                if(ny < airCleanerY[1]) break;
                if(ny == airCleanerY[1] && nx == 0) break;

                board[y][x] = board[ny][nx];
                y = ny;
                x = nx;
            }
        }
        board[y][0] = -1;
        board[y][1] = 0;
    }

    // 먼지 합계
    static int sumDust(){
        int sum = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)    sum += board[i][j];
        }
        return sum + 2;
    }

    // 공기청정기 작동
    static void executeAirCleaner(){
        upAirCleaner();
        downAirCleaner();
    }

    public static void main(String[] args) throws IOException{
        input();
        while(T-- > 0){
            spreadDust();
            executeAirCleaner();
        }
        System.out.println(sumDust());
    }
}