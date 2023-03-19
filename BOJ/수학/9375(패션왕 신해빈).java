import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int test = Integer.parseInt(br.readLine());

        while (test-- > 0) {
            int n = Integer.parseInt(br.readLine());

            HashMap<String, Integer> clothes = new HashMap<>();
            for (int idx=0; idx<n; idx++) {
                String[] line = br.readLine().split(" ");

                if (clothes.containsKey(line[1]))   clothes.put(line[1], clothes.get(line[1]) + 1);
                else                                clothes.put(line[1], 1);
            }

            int result = 1;
            for (String key : clothes.keySet()) {
                result *= (clothes.get(key) + 1);
            }

            sb.append(result - 1).append("\n");
        }

        System.out.println(sb);
    }
}