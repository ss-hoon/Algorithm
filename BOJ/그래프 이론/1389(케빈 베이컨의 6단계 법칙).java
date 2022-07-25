import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] friend;
        int user, relationship, kevinBacon = Integer.MAX_VALUE, kevinBaconUser = 1;
        final int INF = 1000;

        String[] line = br.readLine().split(" ");
        user = Integer.parseInt(line[0]);
        relationship = Integer.parseInt(line[1]);

        friend = new int[user+1][user+1];

        // Initialize
        for(int i=1; i<=user; i++) {
            for(int j=1; j<=user; j++) {
                friend[i][j] = (i == j ? 0 : INF);
            }
        }

        while(relationship-- > 0) {
            line = br.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);

            friend[start][end] = friend[end][start] = 1;
        }

        // Floyd-Warshall Algorithm
        for(int k=1; k<=user; k++) {
            for(int i=1; i<=user; i++) {
                for(int j=1; j<=user; j++)
                    friend[i][j] = Math.min(friend[i][k] + friend[k][j], friend[i][j]);
            }
        }

        // Search Minimum Kevin-Bacon
        for(int i=1; i<=user; i++) {
            int sum = 0;
            for(int j=1; j<=user; j++)
                sum += friend[i][j];

            if(sum < kevinBacon) {
                kevinBaconUser = i;
                kevinBacon = sum;
            }
        }

        System.out.println(kevinBaconUser);
    }
}