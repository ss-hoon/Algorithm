import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str1 = br.readLine().toCharArray();
        char[] str2 = br.readLine().toCharArray();

        String[][] cache = new String[str1.length+1][str2.length+1];
        for(int i=0; i<=str1.length; i++) {
            for(int j=0; j<=str2.length; j++)    cache[i][j] = "";
        }

        for(int i=1; i<=str1.length; i++) {
            for(int j=1; j<=str2.length; j++) {
                if(str1[i-1] == str2[j-1])  cache[i][j] = cache[i-1][j-1] + str1[i-1];
                else {
                    if(cache[i-1][j].length() < cache[i][j-1].length()) cache[i][j] = cache[i][j-1];
                    else cache[i][j] = cache[i-1][j];
                }
            }
        }

        System.out.println(cache[str1.length][str2.length]);
    }
}