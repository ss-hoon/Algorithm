import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] day = new int[14];
        int seed = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int idx=0; idx<14; idx++) {
            day[idx] = Integer.parseInt(st.nextToken());
        }

        int[] stock = new int[2];
        int[] money = new int[2];
        money[0] = seed;
        money[1] = seed;

        for(int idx=0; idx<14; idx++) {
            if(money[0] / day[idx] > 0) {
                stock[0] += money[0] / day[idx];
                money[0] %= day[idx];
            }
        }

        for(int idx=4; idx<14; idx++) {
            if(day[idx-3] < day[idx-2] && day[idx-2] < day[idx-1] && day[idx-1] < day[idx] && money[1] / day[idx] > 0) {
                money[1] += stock[1] * day[idx];
                stock[1] = 0;
            } else if(day[idx-3] > day[idx-2] && day[idx-2] > day[idx-1] && day[idx-1] > day[idx]) {
                stock[1] += money[1] / day[idx];
                money[1] %= day[idx];
            }
        }

        if(money[0] + stock[0] * day[13] < money[1] + stock[1] * day[13]) {
            System.out.println("TIMING");
        } else if(money[0] == money[1]) {
            System.out.println("SAMESAME");
        } else {
            System.out.println("BNP");
        }
    }
}