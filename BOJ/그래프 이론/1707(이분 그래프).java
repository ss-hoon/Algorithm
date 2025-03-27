import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    private static int V, E;
    private static ArrayList<ArrayList<Integer>> graph = null;
    private static int[] check = null;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder result = new StringBuilder();
        int K = Integer.parseInt(st.nextToken());

        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());

            graph = new ArrayList<>();
            check = new int[V+1];

            for (int idx=0; idx<=V; idx++)
                graph.add(new ArrayList<>());

            while (E-- > 0) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                graph.get(u).add(v);
                graph.get(v).add(u);
            }


            for (int idx=1; idx<=V; idx++) {
                if (check[idx] == 0 && !dfs(idx, 1)) {
                    result.append("NO\n");
                    break;
                }

                if (idx == V) {
                    result.append("YES\n");
                }
            }
        }

        System.out.println(result);
    }

    private static boolean dfs(int node, int color) {
        check[node] = color;

        for (int next : graph.get(node)) {
            if (check[next] == color)    return false;

            if (check[next] == 0 && !dfs(next, 3-color)) {
                return false;
            }
        }

        return true;
    }
}
