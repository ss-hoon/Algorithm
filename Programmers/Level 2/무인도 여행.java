import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collections;

class Solution {
    // 초기화
    private boolean[][] visited;
    private Queue<int[]> que = new LinkedList<>();
    private int[] dx = {-1, 0, 0, 1};
    private int[] dy = {0, -1, 1, 0};
    private int lenX, lenY;

    public int[] solution(String[] maps) {

        // 초기화
        ArrayList<Integer> answer = new ArrayList<>();
        lenX = maps.length;
        lenY = maps[0].length();
        visited = new boolean[lenX][lenY];

        // 1. BFS로 하나씩 탐색 (방문한 위치는 다시 방문하지 않도록 체크)
        // 결과를 리스트에 하나씩 담는다.
        for (int i=0; i<lenX; i++) {
            for (int j=0; j<lenY; j++) {
                if (maps[i].charAt(j) == 'X' || visited[i][j])  continue;

                int result = bfs(i, j, maps);

                if (result > 0)     answer.add(result);
            }
        }

        // 2. 지낼 수 없는 무인도 처리 or 리스트 정렬
        if (answer.isEmpty()) { 
            answer.add(-1);
        } else {
            Collections.sort(answer);
        }

        // 3. 결과 반환 (리스트 -> 배열)
        return answer.stream().mapToInt(x -> x).toArray();
    }

    private int bfs(int x, int y, String[] maps) {        
        int sum = 0;
        visited[x][y] = true;
        que.add(new int[] {x, y});

        while (!que.isEmpty()) {
            int[] front = que.poll();
            sum += maps[front[0]].charAt(front[1]) - '0';

            for (int idx=0; idx<4; idx++) {
                int nx = front[0] + dx[idx];
                int ny = front[1] + dy[idx];

                if (nx < 0 || nx >= lenX || ny < 0 || ny >= lenY || maps[nx].charAt(ny) == 'X' || visited[nx][ny])    continue;

                visited[nx][ny] = true;
                que.add(new int[] {nx, ny});
            }
        }

        return sum;
    }
}
