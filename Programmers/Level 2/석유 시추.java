import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    private int[][] visited;
    private int[] sumOil;
    private int[] dx = {-1, 0, 0, 1};
    private int[] dy = {0, -1, 1, 0};
    
    public int solution(int[][] land) {
        // 초기화
        int answer = 0;
        int lenX = land.length;
        int lenY = land[0].length;
        
        visited = new int[lenX][lenY];
        sumOil = new int[lenX * lenY];
        
        // DFS로 모든 석유 탐색하면서 범위 저장
        int oilNumber = 1;
        for (int i=0; i<lenX; i++) {
            for (int j=0; j<lenY; j++) {
                if (land[i][j] == 0 || visited[i][j] > 0)   continue;
                
                sumOil[oilNumber] = searchOil(i, j, oilNumber, lenX, lenY, land);
                oilNumber++;
            }
        }
        
        // 1부터 m까지 반복하며 해당 범위의 석유를 모두 더함
        for (int j=0; j<lenY; j++) {
            int sum = 0;
            Set<Integer> set = new HashSet<>();
            
            for (int i=0; i<lenX; i++) {
                if (visited[i][j] > 0)  set.add(visited[i][j]);
            }
            
            for (int idx : set) {
                sum += sumOil[idx];
            }
            
            answer = Math.max(answer, sum);
        }
        
        return answer;
    }
    
    private int searchOil(int i, int j, int oilNumber, int lenX, int lenY, int[][] land) {
        int sum = 0;
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] {i, j});
        visited[i][j] = oilNumber;
        
        while (!que.isEmpty()) {
            sum++;
            int x = que.peek()[0];
            int y = que.poll()[1];
            
            for (int idx=0; idx<4; idx++) {
                int nextX = x + dx[idx];
                int nextY = y + dy[idx];
                
                if (nextX < 0 || nextX >= lenX || nextY < 0 || nextY >= lenY || land[nextX][nextY] == 0 || visited[nextX][nextY] > 0)   continue;
                
                visited[nextX][nextY] = oilNumber;
                que.add(new int[] {nextX, nextY});
            }
        }
        
        return sum;
    }
}
