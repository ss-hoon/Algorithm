import java.io.*;

public class Main {

    /* UCPC로 축약할 수 있는지 여부 */
    static boolean isUCPC(String str) {
        char[] UCPC = {'U', 'C', 'P', 'C'};
        int pos = 0;

        /* 처음부터 끝까지 반복하면서 UCPC 단어를 찾는다. */
        for(char token : str.toCharArray()) {
            if(token == UCPC[pos] && pos++ == 3) return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(isUCPC(br.readLine()) ? "I love UCPC" : "I hate UCPC");
    }
}