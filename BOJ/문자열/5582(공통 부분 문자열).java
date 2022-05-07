import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] strA = br.readLine().toCharArray();
        char[] strB = br.readLine().toCharArray();

        int[][] cache = new int[strA.length+1][strB.length+1];
        int result = 0;

        for(int i=1; i<=strA.length; i++) {
            for(int j=1; j<=strB.length; j++) {
                if(strA[i-1] == strB[j-1]) {
                    cache[i][j] = cache[i-1][j-1] + 1;
                    result = Math.max(result, cache[i][j]);
                }
            }
        }

        System.out.println(result);
    }
}