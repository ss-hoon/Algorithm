import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int start = Integer.parseInt(line[0]);
        int end = Integer.parseInt(line[1]);

        int result = 1;
        while(true) {
            if(start == end)    break;
            if(start > end || !(end % 10 == 1 || end % 2 == 0)) {
                result = -1;
                break;
            }

            if(end % 10 == 1)   end /= 10;
            else end /= 2;

            result++;
        }

        System.out.println(result);
        br.close();
    }
}