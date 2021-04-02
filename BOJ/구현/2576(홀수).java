import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int min = 101, sum = 0;
        for(int i=0;i<7;i++){
            int x = Integer.parseInt(br.readLine());
            if(x % 2 == 1){
                min = Math.min(min, x);
                sum += x;
            }
        }

        if(sum == 0) System.out.println(-1);
        else{
            System.out.println(sum);
            System.out.println(min);
        }
    }
}