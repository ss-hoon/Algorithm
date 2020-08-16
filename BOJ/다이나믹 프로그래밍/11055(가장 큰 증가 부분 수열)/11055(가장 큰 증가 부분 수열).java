import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
    static int[] sequence;
    static int[] cache;

    static int max_sum(int position, int cnt){
        int max = -1;
        if(cache[position] != -1)   return cache[position];
        if(position == cnt - 1)  return cache[position] = sequence[position];
        for(int index = position + 1; index < cnt; index++) {
            if(sequence[position] < sequence[index])    max = Math.max(max, max_sum(index, cnt));
        }
        if(max == -1)   return cache[position] = sequence[position];
        else return cache[position] = max + sequence[position];
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt = Integer.parseInt(br.readLine());
        int max_num = -1;
        sequence = new int[cnt];
        cache = new int[cnt];
        Arrays.fill(cache, -1);
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int index = 0; index < cnt; index++)    sequence[index] = Integer.parseInt(st.nextToken());
        for(int index = 0; index < cnt; index++)    max_num = Math.max(max_sum(index, cnt), max_num);
        System.out.println(max_num);
    }
}