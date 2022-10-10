import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        int[][] A = new int[H][W];
        int[][] B = new int[H+X][W+Y];

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<H; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<W; j++) {
                B[i][j] = Integer.parseInt(st.nextToken());
                
                // 겹치지 않은 부분은 그대로 적용
                // 겹친 부분은 B 배열에서 A 배열에 해당하는 부분을 뺀 값 적용 
                if(i-X >= 0 && j-Y >= 0) A[i][j] = B[i][j] - A[i-X][j-Y];
                else A[i][j] = B[i][j];

                sb.append(A[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}