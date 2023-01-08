import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int L = Integer.parseInt(line[1]);
        int result = 0;

        String[] temp = br.readLine().split(" ");
        int[] whole = new int[N];
        int[] check = new int[1001];
        for(int i=0; i<N; i++) {
            whole[i] = Integer.parseInt(temp[i]);
            check[whole[i]] = 1;
        }

        for(int idx=0; idx<1001; idx++) {
            if(check[idx] == 1) {
                idx = idx + L - 1;
                result++;
            }
        }

        System.out.println(result);
    }
}