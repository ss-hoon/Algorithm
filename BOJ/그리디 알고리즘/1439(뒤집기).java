import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();
        int[] count = new int[2];

        count[line.charAt(0)-'0']++;
        for(int idx=1; idx<line.length(); idx++) {
            if(line.charAt(idx-1) != line.charAt(idx)) {
                count[line.charAt(idx)-'0']++;
            }
        }

        System.out.println(Math.min(count[0], count[1]));
    }
}