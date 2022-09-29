import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int time = Integer.parseInt(st.nextToken());

        int distP = p + time;
        int distQ = q + time;

        int x = ((distP / w) % 2 == 0) ? (distP % w) : w - (distP % w);
        int y = ((distQ / h) % 2 == 0) ? (distQ % h) : h - (distQ % h);

        System.out.println(x + " " + y);
    }
}