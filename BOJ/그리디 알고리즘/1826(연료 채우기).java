import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Station {
        int pos, oil;

        Station(int pos, int oil) {
            this.pos = pos;
            this.oil = oil;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Station> pq1 = new PriorityQueue<>(new Comparator<Station>() {
            @Override
            public int compare(Station o1, Station o2) {
                return o1.pos - o2.pos;
            }
        });

        PriorityQueue<Station> pq2 = new PriorityQueue<>(new Comparator<Station>() {
            @Override
            public int compare(Station o1, Station o2) {
                return o2.oil - o1.oil;
            }
        });

        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());

        for (int idx=0; idx<N; idx++) {
            st = new StringTokenizer(br.readLine());
            pq1.add(new Station(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        st = new StringTokenizer(br.readLine());
        int[] finish = { Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) };

        int result = 0, current = finish[1];
        while (current < finish[0]) {
            while (!pq1.isEmpty() && pq1.peek().pos <= current) {
                pq2.add(pq1.poll());
            }

            if(pq2.isEmpty())    break;

            result++;
            current += pq2.poll().oil;
        }

        System.out.println(pq2.isEmpty() && current < finish[0] ? -1 : result);
    }
}