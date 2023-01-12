import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList<Integer> list = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        int pivot = 0;
        while(st.hasMoreTokens()) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(list);
        for(int num : list) {
            if(num > 0)
                break;

            pivot++;
        }

        int result = 0;
        for(int idx=0; idx<pivot; idx+=M)
            result += Math.abs(list.get(idx)) * 2;

        for(int idx=N-1; idx>=pivot; idx-=M)
            result += Math.abs(list.get(idx)) * 2;

        if(Math.abs(list.get(0)) < Math.abs(list.get(N-1)))
            result -= Math.abs(list.get(N-1));
        else
            result -= Math.abs(list.get(0));

        System.out.println(result);
    }
}