import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] array;
    static int[][] board;

    static boolean check(int N, int M) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(array[i][j] != board[i][j])
                    return false;
            }
        }

        return true;
    }

    static void change(int startY, int startX) {
        for(int i=startY; i<=startY+2; i++) {
            for(int j=startX; j<=startX+2; j++) {
                board[i][j] ^= 1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        array = new int[N][M];
        board = new int[N][M];

        for(int i=0; i<N; i++) {
            char[] row = br.readLine().toCharArray();
            for (int j=0; j<M; j++)
                board[i][j] = row[j] - '0';
        }

        for(int i=0; i<N; i++) {
            char[] row = br.readLine().toCharArray();
            for (int j=0; j<M; j++)
                array[i][j] = row[j] - '0';
        }

        int result = 0;
        for (int i=0; i<N-2; i++) {
            for (int j=0; j<M-2; j++) {
                if(board[i][j] != array[i][j]) {
                    change(i, j);
                    result++;
                }
            }
        }

        System.out.println(check(N, M) ? result : -1);
    }
}