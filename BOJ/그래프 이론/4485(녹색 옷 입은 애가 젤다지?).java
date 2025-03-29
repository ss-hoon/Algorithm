import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    private static int[] dx = {0, -1, 1, 0};
    private static int[] dy = {-1, 0, 0, 1};
    private static int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();
        int N = 0;
        int test = 0;

        while ((N = Integer.parseInt(br.readLine())) > 0 && ++test > 0) {
            PriorityQueue<Vertex> pq = new PriorityQueue<>();
            int[][] graph = new int[N][N];
            int[][] minCost = new int[N][N];

            for (int i=0; i<N; i++) {
                Arrays.fill(minCost[i], INF);
                String line = br.readLine();

                for (int j=0; j<N; j++)
                    graph[i][j] = line.charAt(2*j) - '0';
            }

            pq.add(new Vertex(0, 0, graph[0][0]));
            minCost[0][0] = graph[0][0];

            while (!pq.isEmpty()) {
                Vertex vertex = pq.poll();

                if (vertex.x == N-1 && vertex.y == N-1) {
                    result.append("Problem ").append(test).append(": ").append(vertex.cost).append('\n');
                    break;
                }

                for (int idx=0; idx<4; idx++) {
                    int nextX = vertex.x + dx[idx];
                    int nextY = vertex.y + dy[idx];

                    if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                        int nextCost = vertex.cost + graph[nextX][nextY];

                        if (nextCost < minCost[nextX][nextY]) {
                            minCost[nextX][nextY] = nextCost;
                            pq.add(new Vertex(nextX, nextY, nextCost));
                        }
                    }
                }
            }
        }

        System.out.println(result);
    }

    private static class Vertex implements Comparable<Vertex> {
        int x, y, cost;

        public Vertex (int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Vertex v) {
            return this.cost - v.cost;
        }
    }
}
