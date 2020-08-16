import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int test = Integer.parseInt(br.readLine());
        while(test-- > 0){
            int people = Integer.parseInt(br.readLine());
            int[] score = new int[people+1];
            for(int i=0;i<people;i++){
                String[] temp = br.readLine().split(" ");
                int document = Integer.parseInt(temp[0]);
                int interview = Integer.parseInt(temp[1]);

                score[document] = interview;
            }

            int tmp = score[1];
            int cnt = 1;

            for(int i=2;i<=people;i++){
                if(tmp > score[i]){
                    tmp = score[i];
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
}