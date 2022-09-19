import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int L = Integer.parseInt(br.readLine());
        char[] pattern = br.readLine().toCharArray();

        int[] table = new int[L];
        int j=0;
        for(int i=1; i<L; i++) {
            while(j>0 && pattern[i] != pattern[j]) {
                j=table[j-1];
            }

            if(pattern[i] == pattern[j]) {
                table[i] = ++j;
            }
        }

        System.out.println(L - table[L-1]);
        br.close();
    }
}