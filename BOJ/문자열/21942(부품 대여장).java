import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] monthList = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
        int N = Integer.parseInt(st.nextToken());

        String format = st.nextToken();
        int DDD = Integer.parseInt(format.substring(0, 3));
        int hh = Integer.parseInt(format.substring(4, 6));
        int mm = Integer.parseInt(format.substring(7, 9));
        int rentalPeriod = DDD * 24 * 60 + hh * 60 + mm;

        int fine = Integer.parseInt(st.nextToken());

        TreeMap<String, Long> fineCog = new TreeMap<>();
        HashMap<String, Long> rentCog = new HashMap<>();
        for(int idx=0; idx<N; idx++) {
            st = new StringTokenizer(br.readLine());

            String[] date = st.nextToken().split("-");
            long time = (monthList[Integer.parseInt(date[1])] + Integer.parseInt(date[2])) * 24 * 60;

            String[] dateTime = st.nextToken().split(":");
            time += Integer.parseInt(dateTime[0]) * 60 + Integer.parseInt(dateTime[1]);

            String renterKey = st.nextToken() + "-" + st.nextToken();

            if(rentCog.containsKey(renterKey)) {
                long calc = (time - rentCog.get(renterKey));
                long fee = calc < 0 ? 0 : calc * fine;

                if(fee > 0) {
                    String renter = renterKey.substring(renterKey.indexOf("-") + 1);
                    fineCog.put(renter, fineCog.containsKey(renter) ? fineCog.get(renter) + fee : fee);
                }

                rentCog.remove(renterKey);
            } else {
                rentCog.put(renterKey, time + rentalPeriod);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(Map.Entry<String, Long> item : fineCog.entrySet()) {
            sb.append(item.getKey()).append(" ").append(item.getValue()).append("\n");
        }

        System.out.println(sb.length() == 0 ? -1 : sb);
    }
}