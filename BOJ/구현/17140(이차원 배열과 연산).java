import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Pair implements Comparable<Pair> {
        int num, cnt;

        Pair(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Pair p) {
            if (p.cnt == this.cnt) {
                return this.num - p.num;
            } else {
                return this.cnt - p.cnt;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int row = 3;
        int col = 3;

        int[][] arr = new int[101][101];
        for (int i=1; i<=3; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=1; j<=3; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int time = 0;
        while (time <= 100) {

            if (arr[r][c] == k) {
                break;
            }

            time++;

            // Init
            int[] check = new int[101];
            int len = 0;

            // 1. R연산(true), C연산(false) 체크
            boolean type = row >= col;

            // 2. 행 또는 열 정렬 계산
            // 3. 데이터 우선순위 큐에 주입한 후 나온 순서대로 배열에 데이터 세팅
            if (type) { // R연산
                for (int i=1; i<=row; i++) {
                    int maxNum = 0;
                    for (int j=1; j<=col; j++) {
                        if(arr[i][j] == 0)  continue;

                        check[arr[i][j]]++;
                        maxNum = Math.max(maxNum, arr[i][j]);
                    }

                    PriorityQueue<Pair> pq = new PriorityQueue<>();
                    for (int idx=1; idx<=maxNum; idx++) {
                        if (check[idx] != 0)
                            pq.add(new Pair(idx, check[idx]));
                    }

                    int cursor = 1;
                    while (!pq.isEmpty()) {
                        if (cursor > 100)   pq.clear();
                        else {
                            arr[i][cursor++] = pq.peek().num;
                            arr[i][cursor++] = pq.poll().cnt;
                        }
                    }

                    len = Math.max(len, cursor-1);

                    check = new int[101];
                    for(int j=cursor; j<=100; j++) arr[i][j] = 0;
                }

                col = len;
            } else { // C연산
                for (int j=1; j<=col; j++) {
                    int maxNum = 0;
                    for (int i=1; i<=row; i++) {
                        if(arr[i][j] == 0)  continue;

                        check[arr[i][j]]++;
                        maxNum = Math.max(maxNum, arr[i][j]);
                    }

                    PriorityQueue<Pair> pq = new PriorityQueue<>();
                    for (int idx=1; idx<=maxNum; idx++) {
                        if (check[idx] != 0)
                            pq.add(new Pair(idx, check[idx]));
                    }

                    int cursor = 1;
                    while (!pq.isEmpty()) {
                        if (cursor > 100)   pq.clear();
                        else {
                            arr[cursor++][j] = pq.peek().num;
                            arr[cursor++][j] = pq.poll().cnt;
                        }
                    }

                    len = Math.max(len, cursor-1);

                    check = new int[101];
                    for(int i=cursor; i<=100; i++) arr[i][j] = 0;
                }

                row = len;
            }
        }

        System.out.println(time > 100 ? -1 : time);
    }
}