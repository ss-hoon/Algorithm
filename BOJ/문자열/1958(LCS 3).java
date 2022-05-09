import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] strA = br.readLine().toCharArray();
        char[] strB = br.readLine().toCharArray();
        char[] strC = br.readLine().toCharArray();

        int[][][] cache = new int[strA.length+1][strB.length+1][strC.length+1];

        for(int i=1; i<=strA.length; i++) {
            for(int j=1; j<=strB.length; j++) {
                for(int k=1; k<=strC.length; k++) {
                    if(strA[i-1] == strB[j-1] && strB[j-1] == strC[k-1]) {
                        cache[i][j][k] = cache[i-1][j-1][k-1] + 1;
                    } else {
                        cache[i][j][k] = Math.max(cache[i-1][j][k], Math.max(cache[i][j-1][k], cache[i][j][k-1]));
                    }
                }
            }
        }

        System.out.println(cache[strA.length][strB.length][strC.length]);
    }
}