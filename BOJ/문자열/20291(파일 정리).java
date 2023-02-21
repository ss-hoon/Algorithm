import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TreeMap<String, Integer> dict = new TreeMap<>();
        int N = Integer.parseInt(br.readLine());

        while(N-- > 0) {
            String file = br.readLine();
            String ext = file.substring(file.indexOf('.') + 1);

            if(dict.containsKey(ext)) {
                dict.put(ext, dict.get(ext) + 1);
            } else {
                dict.put(ext, 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(Map.Entry<String, Integer> map : dict.entrySet()) {
            sb.append(map.getKey()).append(" ").append(map.getValue()).append("\n");
        }

        System.out.println(sb);
    }
}