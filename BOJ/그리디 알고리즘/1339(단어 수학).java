import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int result = 0, max = 9;
        int[] alpha = new int[26];

        for (int i=0; i<N; i++) {
            char[] word = br.readLine().toCharArray();

            for (int j=0; j<word.length; j++) {
                alpha[word[j] - 'A'] -= Math.pow(10, word.length - j - 1);
            }
        }

        Arrays.sort(alpha);
        for (int idx=0; idx<26; idx++) {
            result += (-alpha[idx] * max--);
        }

        System.out.println(result);
    }
}