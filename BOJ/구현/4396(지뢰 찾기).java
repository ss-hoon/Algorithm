import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        int mineCnt = 0;

        int n = Integer.parseInt(br.readLine());
        int[][] mines = new int[n*n][2];
        char[][] board = new char[n][n];
        char[][] endBoard = new char[n][n];
        int[][] count = new int[n][n];

        for(int i=0; i<n; i++) {
            char[] temp = br.readLine().toCharArray();
            for(int j=0; j<n; j++) {
                board[i][j] = temp[j];

                if(temp[j] == '*') {
                    mines[mineCnt][0] = i;
                    mines[mineCnt][1] = j;

                    mineCnt++;
                }
            }
        }

        for(int i=0; i<n; i++) {
            char[] temp = br.readLine().toCharArray();
            for(int j=0; j<n; j++) {
                endBoard[i][j] = temp[j];
            }
        }

        boolean isLose = false;
        for(int i=0; i<mineCnt; i++) {
            int mineY = mines[i][0];
            int mineX = mines[i][1];

            for(int j=0; j<8; j++) {
                int y = mineY + dy[j];
                int x = mineX + dx[j];

                if(y < 0 || y >= n || x < 0 || x >= n)  continue;

                count[y][x]++;
            }

            if(endBoard[mineY][mineX] == 'x')   isLose = true;
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isLose && board[i][j] == '*')    sb.append("*");
                else if(endBoard[i][j] == 'x')      sb.append(count[i][j]);
                else sb.append(".");
            }

            sb.append("\n");
        }

        System.out.println(sb);
    }
}