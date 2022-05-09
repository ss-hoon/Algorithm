import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S, T;
        boolean isReverse = false;

        S = br.readLine();
        T = br.readLine();
        int start = 0;
        int end = T.length()-1;

        while(S.length() < end - start + 1) {
            int idx = isReverse ? start++ : end--;
            if(T.charAt(idx) == 'B')    isReverse = !isReverse;
        }

        String test = T.substring(start, end+1);
        if(isReverse)   test = new StringBuilder(test).reverse().toString();
        System.out.println(test.equals(S) ? 1 : 0);
    }
}