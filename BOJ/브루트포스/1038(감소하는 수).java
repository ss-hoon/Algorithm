import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    static ArrayList<Long> decreaseNumList = new ArrayList<>();

    private static void make(long now, int n) {
        decreaseNumList.add(now);

        for(int i=n-1; i>=0; i--)
            make(10 * now + i, i);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        for(int i=0; i<10; i++) make(i, i);
        Collections.sort(decreaseNumList);

        System.out.println(N < decreaseNumList.size() ? decreaseNumList.get(N) : Long.valueOf(-1));
    }
}