import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static class Pair implements Comparable<Pair> {
        int day, score;

        Pair(int day, int score) {
            this.day = day;
            this.score = score;
        }

        @Override
        public int compareTo(Pair p) {
            return p.score - this.score;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Pair[] slot = new Pair[N];
        for(int idx=0; idx<N; idx++) {
            String[] line = br.readLine().split(" ");

            int d = Integer.parseInt(line[0]);
            int w = Integer.parseInt(line[1]);

            slot[idx] = new Pair(d, w);
        }

        Arrays.sort(slot);

        boolean[] calendar = new boolean[1001];
        int result = 0;
        for(int ptr=0; ptr<N; ptr++) {
            Pair p = slot[ptr];

            for(int idx=p.day; idx>=1; idx--) {
                if(!calendar[idx]) {
                    calendar[idx] = true;
                    result += p.score;
                    break;
                }
            }
        }

        System.out.println(result);
    }
}