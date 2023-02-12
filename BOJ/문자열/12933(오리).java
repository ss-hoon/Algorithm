import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] quack = new int[5];
        char[] sounds = br.readLine().toCharArray();

        int result = 0;
        for(char token : sounds) {
            int target = "quack".indexOf(token);

            if(token == 'q') {
                quack[0]++;
                result = Math.max(result, quack[0]);
            } else {
                if(quack[target-1] <= quack[target]) {
                    result = -1;
                    break;
                }
                quack[target]++;

                if(token == 'k') {
                    for(int idx=0; idx<5; idx++)
                        quack[idx]--;
                }
            }
        }

        System.out.println((quack[0] > 0 || quack[1] > 0 || quack[2] > 0 || quack[3] > 0) ? -1 : result);
    }
}