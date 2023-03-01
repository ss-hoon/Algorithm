import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        String[][] people = new String[n][2];

        for(int idx=0; idx<n; idx++) {
            st = new StringTokenizer(br.readLine());

            String name = st.nextToken();
            String day = st.nextToken();
            String month = st.nextToken();
            String year = st.nextToken();

            people[idx][0] = year + String.format("%02d", Integer.parseInt(month)) + String.format("%02d", Integer.parseInt(day));
            people[idx][1] = name;
        }

        Arrays.sort(people, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                return o1[0].compareTo(o2[0]);
            }
        });

        System.out.println(people[n-1][1]);
        System.out.println(people[0][1]);
    }
}