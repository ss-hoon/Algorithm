import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[][] neural;
    static int pooling(int y1, int x1, int y2, int x2) {
        int[] list = new int[4];

        if(y2 - y1 > 1) {
            list[0] = pooling(y1, x1, ((y1 + y2) >> 1), ((x1 + x2) >> 1));
            list[1] = pooling(y1, ((x1 + x2) >> 1) + 1, ((y1 + y2) >> 1),  x2);
            list[2] = pooling(((y1 + y2) >> 1) + 1, x1, y2, ((x1 + x2) >> 1));
            list[3] = pooling(((y1 + y2) >> 1) + 1, ((x1 + x2) >> 1) + 1, y2, x2);
        } else {
            list[0] = neural[y1][x1];
            list[1] = neural[y1][x2];
            list[2] = neural[y2][x1];
            list[3] = neural[y2][x2];
        }

        Arrays.sort(list);
        return list[2];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        neural = new int[N][N];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++) {
                neural[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(pooling(0, 0, N-1, N-1));
    }
}