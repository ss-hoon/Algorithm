import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] table;
    static char[] origin, pattern;
    static int count;
    static StringBuilder result = new StringBuilder();

    static void makeTable() {
        table = new int[pattern.length];
        int len = 0;
        for(int idx=1; idx<pattern.length; idx++) {
            while(len>0 && pattern[len] != pattern[idx])
                len = table[len-1];

            if(pattern[len] == pattern[idx])
                table[idx] = ++len;
        }
    }

    static void KMP() {
        int len=0;
        for(int idx=0; idx<origin.length; idx++) {
            while(len>0 && pattern[len] != origin[idx])
                len = table[len-1];

            if(pattern[len] == origin[idx]) {
                if(len == pattern.length-1) {
                    result.append(idx-pattern.length+2).append(" ");
                    count++;
                    len = table[len];
                } else {
                    len++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        origin = br.readLine().toCharArray();
        pattern = br.readLine().toCharArray();

        makeTable();
        KMP();

        System.out.println(count);
        System.out.println(result);
    }
}