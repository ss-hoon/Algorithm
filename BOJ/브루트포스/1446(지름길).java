import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    static ArrayList<Shortcut> shortcutList = new ArrayList<>();
    static int finish, result;

    static class Shortcut implements Comparable<Shortcut> {
        int start, end, dist;

        Shortcut(int start, int end, int dist) {
            this.start = start;
            this.end = end;
            this.dist = dist;
        }

        @Override
        public int compareTo(Shortcut s) {
            return this.start - s.start;
        }
    }

    private static void getMinDistance(int pos, int idx, int sum) {
        if(idx == shortcutList.size()) {
            result = Math.min(result, finish - pos + sum);
            return;
        }

        Shortcut shortcut = shortcutList.get(idx);
        
        // 지름길을 선택하는 경우
        if(shortcut.start >= pos)
            getMinDistance(shortcut.end, idx+1, sum + shortcut.start - pos + shortcut.dist);
        
        // 지름길을 선택하지 않는 경우
        getMinDistance(pos, idx+1, sum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int N = Integer.parseInt(line[0]);
        result = finish = Integer.parseInt(line[1]);

        while(N-- > 0) {
            line = br.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);
            int dist = Integer.parseInt(line[2]);

            if(end - start < dist || finish < end)  continue;

            shortcutList.add(new Shortcut(start, end, dist));
        }

        Collections.sort(shortcutList);
        getMinDistance(0, 0, 0);

        System.out.println(result);
        br.close();
    }
}