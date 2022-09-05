import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

    static String[] english = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    static class Pair implements Comparable<Pair> {
        int num;
        String eng;

        Pair(int num, String eng) {
            this.num = num;
            this.eng = eng;
        }

        @Override
        public int compareTo(Pair p) {
            return this.eng.compareTo(p.eng);
        }
    }

    static String numToEng(int num) {
        String eng = String.valueOf(num);

        if(eng.length() == 1)   return english[num];
        return english[eng.charAt(0) - '0'] + " " + english[eng.charAt(1) - '0'];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int start = Integer.parseInt(line[0]);
        int end = Integer.parseInt(line[1]);

        PriorityQueue<Pair> pq = new PriorityQueue<>();

        for(int idx=start; idx<=end; idx++)
            pq.add(new Pair(idx, numToEng(idx)));

        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()) {
            sb.append(pq.poll().num).append(" ");
            cnt++;

            if(cnt == 10) {
                sb.append("\n");
                cnt = 0;
            }
        }

        System.out.println(sb);
        br.close();
    }
}