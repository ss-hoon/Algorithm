import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {

    static int N, M, cntCountry;
    static int[][] map, dist;
    static boolean[][] visit;
    static ArrayList<Position>[] country = new ArrayList[6];
    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    static PriorityQueue<Road> pq = new PriorityQueue<>();
    static int[] parent;

    static class Position {
        int y, x;

        Position(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Road implements Comparable<Road> {
        int start, end, weight;

        Road(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Road r) {
            return this.weight - r.weight;
        }
    }

    static void searchCountry(int y, int x) {
        country[cntCountry].add(new Position(y, x));
        visit[y][x] = true;
        map[y][x] = cntCountry+1;

        for(int idx=0; idx<4; idx++) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == 0 || visit[ny][nx])  continue;

            searchCountry(ny, nx);
        }
    }

    static void getDistanceBetweenCountry(int start) {
        for(Position pos : country[start]) {
            for(int idx=0; idx<4; idx++) {
                for(int step=1; step<Math.max(N, M); step++) {
                    int y = pos.y + dy[idx] * step;
                    int x = pos.x + dx[idx] * step;

                    if(y < 0 || y >= N || x < 0 || x >= M)  break;

                    if(map[y][x] != 0) {
                        if((map[y][x]-1) != start && step > 2)
                            dist[start][(map[y][x]-1)] = Math.min(dist[start][(map[y][x]-1)], step-1);

                        break;
                    }
                }
            }
        }
    }

    static int find(int tgt) {
        if(tgt == parent[tgt])  return tgt;

        return parent[tgt] = find(parent[tgt]);
    }

    static void union(int c1, int c2) {
        c1 = find(c1);
        c2 = find(c2);

        if(c1 == c2)    return;

        parent[c1] = parent[c2] = Math.min(c1, c2);
    }

    static boolean isCycle(int c1, int c2) {
        c1 = find(c1);
        c2 = find(c2);

        return c1 == c2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Initialize
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        map = new int[N][M];
        dist = new int[N][M];
        visit = new boolean[N][M];
        for(int idx=0; idx<6; idx++)
            country[idx] = new ArrayList<>();

        for(int i=0; i<N; i++) {
            line = br.readLine().split(" ");
            for(int j=0; j<M; j++)
                map[i][j] = Integer.parseInt(line[j]);
        }

        // 1) DFS 알고리즘으로 국가 찾기 -> List에 저장 (Position 클래스 사용)
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] == 0 || visit[i][j])    continue;

                searchCountry(i, j);
                cntCountry++;
            }
        }

        // 2) Brute Force 알고리즘으로 국가 간 거리 PriorityQueue에 저장 (Road 클래스 사용)
        dist = new int[cntCountry][cntCountry];
        for(int i=0; i<cntCountry; i++) {
            for(int j=0; j<cntCountry; j++)
                dist[i][j] = Integer.MAX_VALUE;
        }
        
        for(int start=0; start<cntCountry; start++)
            getDistanceBetweenCountry(start);

        for(int i=0; i<cntCountry; i++) {
            for(int j=i+1; j<cntCountry; j++) {
                if(dist[i][j] == Integer.MAX_VALUE) continue;

                pq.add(new Road(i, j, dist[i][j]));
            }
        }

        // 3) Kruskal 알고리즘으로 최소 비용 간선부터 하나씩 연결 (Union-find 알고리즘으로 사이클 판단)
        int cntConnect = 0;
        int result = 0;
        parent = new int[cntCountry];
        for(int idx=0; idx<cntCountry; idx++)
            parent[idx] = idx;

        while(!pq.isEmpty()) {
            if(cntConnect == cntCountry-1)  break;

            Road road = pq.poll();
            if(isCycle(road.start, road.end))   continue;

            result += road.weight;
            union(road.start, road.end);
            cntConnect++;
        }

        if(cntConnect != cntCountry-1)  result = -1;

        // 4) 간선 합 출력
        System.out.println(result);
        br.close();
    }
}