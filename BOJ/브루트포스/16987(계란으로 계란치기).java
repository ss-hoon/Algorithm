import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] durability, weight;

    static int breakEgg(int order) {
        if (order == N) return 0;
        if (durability[order] <= 0)   return breakEgg(order+1);

        int ret = 0;
        for (int idx=0; idx<N; idx++) {
            if (order == idx || durability[idx] <= 0)    continue;

            durability[order] -= weight[idx];
            durability[idx] -= weight[order];

            int cnt = 0;
            if (durability[order] <= 0) cnt++;
            if (durability[idx] <= 0) cnt++;

            cnt += breakEgg(order+1);

            durability[order] += weight[idx];
            durability[idx] += weight[order];

            ret = Math.max(ret, cnt);
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        durability = new int[N];
        weight = new int[N];

        for (int idx=0; idx<N; idx++) {
            String[] line = br.readLine().split(" ");

            durability[idx] = Integer.parseInt(line[0]);
            weight[idx] = Integer.parseInt(line[1]);
        }

        System.out.println(breakEgg(0));
    }
}