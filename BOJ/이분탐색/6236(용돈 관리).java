import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);

        int[] money = new int[N];
        int minMoney = 0, maxMoney = 0;
        for (int idx=0; idx<N; idx++) {
            money[idx] = Integer.parseInt(br.readLine());
            minMoney = Math.max(minMoney, money[idx]);
            maxMoney += money[idx];
        }

        while (minMoney < maxMoney) {
            int midMoney = (minMoney + maxMoney) / 2;
            int currentMoney = midMoney;
            int count = 1;

            for (int idx=0; idx<N; idx++) {
                if (currentMoney < money[idx]) {
                    currentMoney = midMoney;
                    count++;
                }

                currentMoney -= money[idx];
            }

            if (count <= M) {
                maxMoney = midMoney;
            } else {
                minMoney = midMoney + 1;
            }
        }

        System.out.println(minMoney);
    }
}