import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[][] board = new int[19][19];
    // 아래쪽 > 대각선 오른 위쪽 > 오른쪽 > 대각선 오른 아래쪽
    static int[] dy = {1, -1, 0, 1};
    static int[] dx = {0, 1, 1, 1};
    // (반대방향)
    // 위쪽 > 대각선 왼 아래쪽 > 왼쪽 > 대각선 왼 위쪽
    static int[] ry = {-1, 1, 0, -1};
    static int[] rx = {0, -1, -1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 데이터 입력 -> board 배열에 받는 작업
        for(int row=0; row<19; row++) {
            int col = 0;
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            while(st.hasMoreTokens())
                board[row][col++] = Integer.parseInt(st.nextToken());
        }

        // 바둑판 탐색
        // 가장 왼쪽이고 그 중 위쪽에 있는 바둑돌 좌표를 얻는 것이기에
        // 일반적인 배열탐색법인 행 -> 열이 아닌 열 -> 행 순으로 탐색한다.

        // 이 방법은 무한루프에 빠질 위험이 없고 4방향만 탐색하면 되기에
        // 8방향을 탐색하는 방법보다 속도를 향상시킬 수 있다.
        loop: for(int col=0; col<19; col++) {
                for(int row=0; row<19; row++) {
                    // 바둑돌이 없는 경우는 탐색할 필요가 없다.
                    if(board[row][col] == 0)
                        continue;

                    // 4방향 탐색
                    for(int dir=0; dir<4; dir++){
                        // 현재 방향으로 5개의 동일한 바둑돌이 존재하는지 체크
                        // 오목으로 판별됐으나, 반대방향 첫번째 바둑돌의 색이 현재 바둑돌의 색과 같다면 육목으로 판별하고 다시 loop 진행
                        // 오목으로 판별된 경우, 현재 위치의 좌표를 출력하고 loop 탈출
                        if(search(row, col, dir, 1) && (!isValidateNum(row + ry[dir], col + rx[dir]) || board[row + ry[dir]][col + rx[dir]] != board[row][col])) {
                            sb.append(board[row][col]).append("\n").append(row+1).append(" ").append(col+1);
                            break loop;
                        }
                    }
                }
        }

        // StringBuilder에 값이 없는 경우는 오목이 존재하지 않는 것이므로
        // 승부가 결정되지 않는 것으로 판별 -> 0을 출력
        if(sb.length() == 0)
            sb.append(0);

        System.out.println(sb.toString());
        br.close();
    }

    // 오목 판별
    public static boolean search(int row, int col, int dir, int cnt) {
        // 재귀 기저조건 : 다섯 개의 동일한 바둑돌이 있는 경우
        if(cnt == 5) {
            // 다섯 개의 동일한 바둑돌에 다음 진행방향의 바둑돌이 바둑판 좌표 밖이거나 색이 다른 경우는 오목으로 판단한다.
            if (!isValidateNum(row + dy[dir], col + dx[dir]) || board[row + dy[dir]][col + dx[dir]] != board[row][col])
                return true;

            return false;
        }

        // 다음 바둑돌이 현재 바둑돌의 색과 같다면 cnt를 1개 증가시키고 다음 돌의 위치에서 다시 재귀 순회
        // 만약 다음 바둑돌이 현재 바둑돌의 색과 다르다면 재귀 탈출
        if(isValidateNum(row + dy[dir], col + dx[dir]) && board[row + dy[dir]][col + dx[dir]] == board[row][col]) {
            if(search(row + dy[dir], col + dx[dir], dir, cnt+1))
                return true;
        }

        return false;
    }

    // 좌표가 유효한지(바둑판(19 * 19) 내부에 존재하는지) 체크
    public static boolean isValidateNum(int y, int x) {
        if(y < 0 || y >= 19 || x < 0 || x >= 19)
            return false;

        return true;
    }
}
