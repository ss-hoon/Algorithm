import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static class Turn {
        int time, position;

        Turn(int time, int position) {
            this.time = time;
            this.position = position;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Turn> que = new LinkedList<>();
        boolean[] visit = new boolean[100001];
        int minTime = Integer.MAX_VALUE;
        int result = 0;
        
        // Initialize
        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);
        
        // Search Min Time
        que.add(new Turn(0, N));
        while(!que.isEmpty()) {
            Turn turn = que.poll();

            if(turn.time > minTime) continue;
            if(turn.position == K) {
                minTime = turn.time;
                result++;
                continue;
            }

            visit[turn.position] = true;

            if(turn.position-1 >= 0 && !visit[turn.position-1])         que.add(new Turn(turn.time+1, turn.position-1));
            if(turn.position+1 <= 100000 && !visit[turn.position+1])    que.add(new Turn(turn.time+1, turn.position+1));
            if(turn.position*2 <= 100000 && !visit[turn.position*2])    que.add(new Turn(turn.time+1, turn.position*2));
        }

        System.out.println(minTime);
        System.out.println(result);
    }
}