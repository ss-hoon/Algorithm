import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static boolean[][] check;
    static int[][] apt;
    static ArrayList<Integer> cnt = new ArrayList<Integer>();
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        apt = new int[n][n];
        check = new boolean[n][n];
        int flag = 0;

        for(int i=0;i<n;i++){
            String[] temp = br.readLine().split("");
            for(int j=0;j<n;j++){
                apt[i][j] = Integer.parseInt(temp[j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(apt[i][j] == 1 && check[i][j] == false) {
                    cnt.add(0);
                    dfs(i, j, flag);
                    flag++;
                }
            }
        }

        Collections.sort(cnt);
        System.out.println(flag);
        for(int i=0;i<flag;i++){
            System.out.println(cnt.get(i));
        }
        br.close();
    }

    public static void dfs(int i, int j, int flag){
        if(i < 0 || j < 0 || i >= n || j >= n)    return;
        if(apt[i][j] == 1 && check[i][j] == false) {
            cnt.set(flag, cnt.get(flag) + 1);
            check[i][j] = true;
            dfs(i - 1, j, flag);
            dfs(i, j - 1, flag);
            dfs(i, j + 1, flag);
            dfs(i + 1, j, flag);
        }
    }
}

