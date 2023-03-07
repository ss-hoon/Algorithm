import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] land = new int[N+1][M+1];
        for(int i=1; i<=N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=M; j++) {
                land[i][j] = land[i-1][j] + land[i][j-1] + Integer.parseInt(st.nextToken()) - land[i-1][j-1];
            }
        }

        int K = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while(K-- > 0) {
            st = new StringTokenizer(br.readLine());

            int sY = Integer.parseInt(st.nextToken());
            int sX = Integer.parseInt(st.nextToken());
            int eY = Integer.parseInt(st.nextToken());
            int eX = Integer.parseInt(st.nextToken());

            sb.append(land[eY][eX] - land[eY][sX-1] - land[sY-1][eX] + land[sY-1][sX-1]).append('\n');
        }

        System.out.println(sb);
    }
}