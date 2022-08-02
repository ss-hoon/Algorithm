import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] book = new String[N];

        for(int idx=0; idx<N; idx++)
            book[idx] = br.readLine();

        Arrays.sort(book);

        int cnt = 1;
        int maxCnt = 0;
        String result = book[0];
        for(int idx=1; idx<N; idx++) {
            if(book[idx].equals(book[idx-1])) {
                cnt++;
                if(maxCnt < cnt) {
                    result = book[idx];
                    maxCnt = cnt;
                }
            } else
                cnt = 1;
        }

        System.out.println(result);
    }
}