import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static class Pair {
        int num;
        String oper;

        Pair(int num, String oper) {
            this.num = num;
            this.oper = oper;
        }
    }

    static int operator(Pair p, char cmd) {
        int num = p.num;

        switch (cmd) {
            case 'D':
                num = (num << 1) % 10000;
                break;
            case 'S':
                num = num == 0 ? 9999 : num - 1;
                break;
            case 'L':
                num = (num * 10) % 10000 + (num / 1000);
                break;
            case 'R':
                num = (num % 10) * 1000 + (num / 10);
                break;
        }

        return num;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Pair> que = new LinkedList<>();
        boolean[] visit = new boolean[10000];
        char[] command = {'D', 'S', 'L', 'R'};

        int T = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();

        while(T-- > 0) {
            Arrays.fill(visit, false);
            String[] line = br.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);

            visit[start] = true;
            que.add(new Pair(start, ""));
            while(!que.isEmpty()) {
                Pair p = que.poll();

                if(p.num == end) {
                    result.append(p.oper).append("\n");
                    break;
                }

                for(int idx=0; idx<4; idx++) {
                    int num = operator(p, command[idx]);

                    if(visit[num])  continue;
                    visit[num] = true;
                    que.add(new Pair(num, p.oper + command[idx]));
                }
            }

            while(!que.isEmpty())
                que.poll();
        }

        System.out.println(result);
    }
}