import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int idx = 0, cnt = 0;
        char[] line = br.readLine().toCharArray();

        for(; idx<line.length; idx++) {
            if(line[idx] == 'P')    cnt++;
            else {
                if(cnt >= 2 && idx < line.length - 1 && line[idx+1] == 'P') {
                    idx++;
                    cnt--;
                }
                else break;
            }
        }

        System.out.println(idx == line.length && cnt == 1 ? "PPAP" : "NP");
    }
}