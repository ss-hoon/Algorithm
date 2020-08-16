import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean[][] paper = new boolean[100][100];
        int sum = 0;
        int colorPaper = sc.nextInt();
        while (colorPaper > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            for (int i = x; i < x + 10; i++) {
                for (int j = y; j < y + 10; j++)    paper[i][j] = true;
            }
            colorPaper--;
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (paper[i][j] == true)    sum++;
            }
        }
        System.out.println(sum);
    }
}