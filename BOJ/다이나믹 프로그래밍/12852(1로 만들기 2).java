import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Queue<Node> que = new LinkedList<>();        // BFS를 위한 큐
    static boolean[] visited = new boolean[1000001];    // 메모이제이션

    /* 메모이제이션을 위한 Node 클래스 */
    static class Node {
        int num;                // 번호
        int depth;              // 연산 수
        StringBuilder path;     // 최소 경로

        Node(int num, int depth, StringBuilder path) {
            this.num = num;
            this.depth = depth;
            this.path = path;
        }
    }

    /* 어떤 수 X를 최소 연산을 통해 1로 만드는 메소드 */
    static void minCalc(int X) {
        que.add(new Node(X, 0, new StringBuilder(String.valueOf(X))));      // Init
        /* BFS */
        while(!que.isEmpty()) {
            Node top = que.poll();
            int num = top.num;
            int depth = top.depth;
    
            /* 1일 때 연산 수와 지금까지의 경로 출력 */
            if(num == 1) {
                System.out.println(top.depth);
                System.out.println(top.path.toString());
                break;
            }

            /* 3의 배수이고 num / 3에 한번도 방문하지 않은 경우 */
            if(num % 3 == 0 && !visited[num / 3]) {
                que.add(new Node(num / 3, depth + 1,  new StringBuilder(top.path).append(" ").append(num / 3)));
                visited[num / 3] = true;
            }

            /* 2의 배수이고 num / 2에 한번도 방문하지 않은 경우 */
            if(num % 2 == 0 && !visited[num / 2]) {
                que.add(new Node(num / 2, depth + 1, new StringBuilder(top.path).append(" ").append(num / 2)));
                visited[num / 2] = true;
            }

            /* num - 1에 한번도 방문하지 않은 경우 */
            if(!visited[num - 1]) {
                que.add(new Node(num - 1, depth + 1, new StringBuilder(top.path).append(" ").append(num - 1)));
                visited[num - 1] = true;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int num = Integer.parseInt(br.readLine());
        minCalc(num);
    }
}