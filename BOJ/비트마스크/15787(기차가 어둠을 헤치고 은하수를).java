import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] train;
    static void operation(int type, int order, String seat) {
        int seatNumber = seat == null ? 0 : Integer.parseInt(seat);

        switch (type) {
            case 1:
                train[order] |= (1 << seatNumber-1);
                break;
            case 2:
                train[order] &= ~(1 << seatNumber-1);
                break;
            case 3:
                train[order] <<= 1;
                if(train[order] >= 1048576)  train[order] &= ~(1 << 20);
                break;
            case 4:
                train[order] >>= 1;
                break;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        train = new int[N+1];
        while(M-- > 0) {
            st = new StringTokenizer(br.readLine());

            int type = Integer.parseInt(st.nextToken());
            int order = Integer.parseInt(st.nextToken());

            String seat = null;
            if(type == 1 || type == 2) {
                seat = st.nextToken();
            }

            operation(type, order, seat);
        }

        boolean[] check = new boolean[1048577];
        int result = 0;
        for(int idx=1; idx<=N; idx++) {
            if(!check[train[idx]]) {
                result++;
                check[train[idx]] = true;
            }
        }

        System.out.println(result);
    }
}