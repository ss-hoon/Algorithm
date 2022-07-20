import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int city, result = Integer.MAX_VALUE;
    private static int[] citizen;
    private static ArrayList<Integer>[] adj;

    private static void combination(int n, ArrayList<Integer> group) {
        if(n > city) {
            gerrymandering(group);
            return;
        }

        group.add(n);
        combination(n+1, group);
        group.remove(group.size()-1);
        combination(n+1, group);
    }

    private static void gerrymandering(ArrayList<Integer> A) {
        if(A.size() == 0 || A.size() == city)    return;

        ArrayList<Integer> B = new ArrayList<>();
        for(int idx=1; idx<=city; idx++)
            if(!A.contains(idx)) B.add(idx);

        if(isConnect(A) && isConnect(B)) {
            int citizenGroupA = 0, citizenGroupB = 0;
            for(int citizenA : A)
                citizenGroupA += citizen[citizenA];

            for(int citizenB : B)
                citizenGroupB += citizen[citizenB];

            result = Math.min(result, Math.abs(citizenGroupA - citizenGroupB));
        }
    }

    private static boolean isConnect(ArrayList<Integer> group) {
        boolean[] visit = new boolean[city+1];
        Queue<Integer> que = new LinkedList<>();

        int first = group.get(0);
        int count = 0;
        que.add(first);
        visit[first] = true;

        while(!que.isEmpty()) {
            int front = que.poll();
            count++;

            for(int near : adj[front]) {
                if(!visit[near] && group.contains(near)) {
                    visit[near] = true;
                    que.add(near);
                }
            }
        }

        return count == group.size();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        city = Integer.parseInt(br.readLine());
        citizen = new int[city+1];
        adj = new ArrayList[city+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int idx=1; idx<=city; idx++)
            citizen[idx] = Integer.parseInt(st.nextToken());

        for(int idx=1; idx<=city; idx++) {
            adj[idx] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            while(st.hasMoreTokens())
                adj[idx].add(Integer.parseInt(st.nextToken()));
        }

        combination(1, new ArrayList<>());
        System.out.println(result == Integer.MAX_VALUE ? -1 : result);
    }
}