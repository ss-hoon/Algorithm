import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {

    static int n, k;
    static String[] card;
    static Set<Integer> numList = new HashSet<>();
    static boolean[] visit;

    static void makeNum(int select, String sum) {
        if(select == k) {
            numList.add(Integer.parseInt(sum));
            return;
        }

        for(int idx=0; idx<n; idx++) {
            if(!visit[idx]) {
               visit[idx] = true;
               makeNum(select+1, sum + card[idx]);
               visit[idx] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        card = new String[n];
        visit = new boolean[n];

        for(int idx=0; idx<n; idx++)
            card[idx] = br.readLine();

        makeNum(0, "");
        System.out.println(numList.size());
        br.close();
    }
}