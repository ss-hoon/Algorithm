import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int width, height, allCntPolice, result;
    private static int[] donggeun = new int[2];
    private static int[][] police;

    private static int getDistance(int[] pos) {
        int[] target1 = donggeun[0] < pos[0] ? donggeun : pos;
        int[] target2 = donggeun[0] < pos[0] ? pos : donggeun;
        int sum = 0;

        // 남-북
        if(target1[0] == 1 && target2[0] == 2) {
            sum += height + target1[1] + target2[1];
            return Math.min(sum, height * 2 + width * 2 - sum);
        }

        // 동-서
        if(target1[0] == 3 && target2[0] == 4) {
            sum += width + target1[1] + target2[1];
            return Math.min(sum, height * 2 + width * 2 - sum);
        }

        // 같은 라인
        if(target1[0] == target2[0]) {
            return Math.abs(target1[1] - target2[1]);
        }

        // 인접 (왼쪽)
        if(target2[0] == 3) {
            if(target1[0] == 1)
                return target1[1] + target2[1];
            else
                return target1[1] + height - target2[1];
        }

        // 인접 (오른쪽)
        if(target2[0] == 4) {
            if(target1[0] == 1)
                return width - target1[1] + target2[1];
            else
                return width - target1[1] + height - target2[1];
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 가로, 세로 Initialize
        width = Integer.parseInt(st.nextToken());
        height = Integer.parseInt(st.nextToken());

        // 경비원 수 Initialize
        allCntPolice = Integer.parseInt(br.readLine());
        police = new int[allCntPolice][2];

        // 경비원 위치 Initialize
        for(int idx=0; idx<allCntPolice; idx++) {
            st = new StringTokenizer(br.readLine());
            police[idx][0] = Integer.parseInt(st.nextToken());
            police[idx][1] = Integer.parseInt(st.nextToken());
        }

        // 동근이 위치 Initialize
        st = new StringTokenizer(br.readLine());
        donggeun[0] = Integer.parseInt(st.nextToken());
        donggeun[1] = Integer.parseInt(st.nextToken());

        // 최소 거리 합 구하기
        for(int idx=0; idx<allCntPolice; idx++)
            result += getDistance(police[idx]);
        
        // 최소 거리 합 출력
        System.out.println(result);
    }
}