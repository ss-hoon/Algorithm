import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M, K;
    static int[][] field = new int[11][11];
    static Deque<Integer>[][] tree = new Deque[11][11];
    static Queue<int[]> breed = new LinkedList<>();
    static int[][] nutrient = new int[11][11];
    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        // N, M, K input
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // init 작업
        // 양분 input, field, tree(deque) 초기화
        for(int i=1;i<=N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=N;j++){
                nutrient[i][j] = Integer.parseInt(st.nextToken());
                field[i][j] = 5;
                tree[i][j] = new ArrayDeque<>();
            }
        }

        // 초기 나무 init
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int age = Integer.parseInt(st.nextToken());

            tree[y][x].offer(age);
        }

        // K 년까지 시뮬레이션
        while(K-- > 0){
            SpringSummer();
            fall();
            winter();
        }

        // 결과 출력
        sb.append(treeCnt());
        bw.write(sb.toString());
        bw.flush();
    }

    // 범위 밖이면 true
    static boolean outOfRange(int y, int x){
        if(y < 1 || y > N || x < 1 || x > N)   return true;
        return false;
    }

    // 나무 전체 개수 return
    static int treeCnt(){
        int sum = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                sum += tree[i][j].size();
            }
        }
        return sum;
    }

    // 봄 여름 구현
    static void SpringSummer(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(tree[i][j].isEmpty())    continue;

                int len = tree[i][j].size();
                int sum = 0;
                for(int k=0;k<len;k++){
                    int t = tree[i][j].poll();

                    // 땅의 양분이 나무의 나이보다 많거나 같은 경우
                    // 양분을 나무의 나이만큼 감소
                    // 나무의 나이 + 1
                    // 나무의 나이 + 1이 5의 배수이면 따로 모아놓음
                    if(field[i][j] >= t){
                        field[i][j] -= t;
                        tree[i][j].offer(t+1);

                        if((t+1) % 5 == 0)
                            breed.offer(new int[] {i, j});
                    }
                    // 땅의 양분이 나무의 나이보다 적은 경우
                    // 나무는 양분이 된다 ( 나이 / 2 만큼)
                    else{
                        sum += t / 2;
                    }
                }
                field[i][j] += sum;
            }
        }
    }

    // 가을 구현
    static void fall(){
        // 봄여름에서 따로 빼놨던 묶음을 처리
        while(!breed.isEmpty()){
            int[] t = breed.poll();

            // 8방향 반복하며 범위 밖은 건너뛰고
            // 범위 안에서만 나무를 새로 생성한다
            for(int k=0;k<8;k++){
                int y = t[0] + dy[k];
                int x = t[1] + dx[k];

                if(outOfRange(y, x))    continue;

                tree[y][x].offerFirst(1);
            }
        }
    }

    // 겨울 구현
    static void winter(){
        // 전체 양분 추가
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                field[i][j] += nutrient[i][j];
            }
        }
    }
}