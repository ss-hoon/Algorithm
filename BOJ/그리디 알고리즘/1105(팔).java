import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char[] L = st.nextToken().toCharArray();
        char[] R = st.nextToken().toCharArray();

        int result = 0;
        if(L.length == R.length) {
            for(int idx=0; idx<L.length; idx++) {
                if(L[idx] == '8' && R[idx] == '8')
                    result++;
                else if(L[idx] != R[idx])
                    break;
            }
        }
    
        System.out.println(result);
    }
}