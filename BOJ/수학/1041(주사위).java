import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][] twoSide = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };
    static int[][] threeSide = { {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5} };
    static int minOne = 50, maxOne, minTwo = 100, minThree = 150, sum;

    private static long getResult(long n) {
        if(n == 1)  return sum - maxOne;

        long result = 0L;

        result = minThree * 4;
        result += minTwo * ((n-2) * 4 + (n-1) * 4);
        result += minOne * ((n-2) * (n-1) * 4 + (n-2) * (n-2));

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dice = new int[6];

        long n = Long.parseLong(br.readLine());
        String[] line = br.readLine().split(" ");

        for(int idx=0 ;idx<6; idx++) {
            dice[idx] = Integer.parseInt(line[idx]);
            maxOne = Math.max(maxOne, dice[idx]);
            minOne = Math.min(minOne, dice[idx]);
            sum += dice[idx];
        }

        for(int idx=0; idx<twoSide.length; idx++)
            minTwo = Math.min(minTwo, dice[twoSide[idx][0]] + dice[twoSide[idx][1]]);

        for(int idx=0; idx<threeSide.length; idx++)
            minThree = Math.min(minThree, dice[threeSide[idx][0]] + dice[threeSide[idx][1]] + dice[threeSide[idx][2]]);

        System.out.println(getResult(n));
    }
}