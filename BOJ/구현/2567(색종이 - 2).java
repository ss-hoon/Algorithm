import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean[][] board = new boolean[101][101];
        int[] dy = {-1, 0, 0, 1};
        int[] dx = {0, -1, 1, 0};
        int n = Integer.parseInt(br.readLine());

        while(n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            for(int i=y; i<y+10; i++) {
                for(int j=x; j<x+10; j++) {
                    board[i][j] = true;
                }
            }
        }

        int result = 0;
        for(int i=0; i<101; i++) {
            for(int j=0; j<101; j++) {
                if(board[i][j]) {
                    for(int k=0; k<4; k++) {
                        int Y = i + dy[k];
                        int X = j + dx[k];

                        if(Y < 0 || Y >= 101 || X < 0 || X >= 101)  continue;
                        if(!board[Y][X])    result++;
                    }
                }
            }
        }

        System.out.println(result);
    }
}