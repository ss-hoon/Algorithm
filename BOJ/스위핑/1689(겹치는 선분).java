import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int result = 0, count = 0;
        int N = Integer.parseInt(st.nextToken());
        ArrayList<int[]> lines = new ArrayList<>();

        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());

            lines.add(new int[] {Integer.parseInt(st.nextToken()), 1});
            lines.add(new int[] {Integer.parseInt(st.nextToken()), -1});
        }

        lines.sort((o1, o2) -> {
            if (o1[0] == o2[0]) return o1[1] - o2[1];
            return o1[0] - o2[0];
        });

        for (int[] elements : lines) {
            count += elements[1];
            result = Math.max(result, count);
        }

        System.out.println(result);
    }
}
