import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int student, relationship, havingMoney, cost;
    static int[][] friendCosts;
    static int[] parent;
    static boolean[] isFriend;

    static int find(int x) {
        if(x == parent[x])  return x;

        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b)  return;

        int minValue = Math.min(a, b);
        parent[a] = minValue;
        parent[b] = minValue;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        student = Integer.parseInt(st.nextToken());
        relationship = Integer.parseInt(st.nextToken());
        havingMoney = Integer.parseInt(st.nextToken());

        parent = new int[student+1];
        friendCosts = new int[student][2];
        isFriend = new boolean[student+1];
        st = new StringTokenizer(br.readLine());

        for(int idx=1; idx<=student; idx++) {
            parent[idx] = idx;
            friendCosts[idx-1][0] = idx;
            friendCosts[idx-1][1] = Integer.parseInt(st.nextToken());
        }

        for(int idx=0; idx<relationship; idx++) {
            st = new StringTokenizer(br.readLine());
            int personA = Integer.parseInt(st.nextToken());
            int personB = Integer.parseInt(st.nextToken());

            union(personA, personB);
        }

        Arrays.sort(friendCosts, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });

        for(int idx=1; idx<=student; idx++) {
            int person = find(friendCosts[idx-1][0]);

            if(isFriend[person]) continue;

            isFriend[person] = true;
            cost += friendCosts[idx-1][1];

            if(cost > havingMoney)  break;
        }

        System.out.println(cost <= havingMoney ? cost : "Oh no");
    }
}