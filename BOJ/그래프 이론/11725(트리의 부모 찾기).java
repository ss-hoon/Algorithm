import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static Queue<Integer> que = new LinkedList<>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        int[] parent = new int[N+1];
        for(int i=0;i<=N;i++){
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            adj.get(start).add(end);
            adj.get(end).add(start);
        }

        // BFS 탐색
        que.add(1);
        parent[1] = -1;
        while(!que.isEmpty()){
            int node = que.poll();

            for(int next : adj.get(node)){
                if(parent[next] != 0)   continue;

                parent[next] = node;
                que.add(next);
            }
        }

        for(int i=2;i<=N;i++) sb.append(parent[i]).append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}