import java.io.*;

public class Main {

    /** 컨베이어 벨트 클래스 */
    static class Conveyor {
        int[] belt;         // 컨베이어 벨트 내구도 (문제에서 주어짐)
        boolean[] robot;    // 로봇 위치 (문제에서 주어짐)
        int enter, exit;    // 시작점과 끝점
        int N, K;           // N : 컨베이어 벨트 윗면 길이, K : 내구도 0 개수  (문제에서 주어짐)

        /** 컨베이어 벨트 클래스 생성자 */
        // 컨베이어 벨트를 초기화한다.
        Conveyor(String[] info, int N, int K) {
            this.N = N;
            this.K = K;
            robot = new boolean[2*N];
            belt = new int[2*N];
            for(int idx=0; idx<2*N; idx++) {
                belt[idx] = Integer.parseInt(info[idx]);
            }

            exit = N-1;
            enter = 0;
        }

        // 컨베이어 벨트와 로봇 위치를 회전시킨다.
        // 컨베이어 벨트와 로봇 위치를 하나하나 회전하지 않고 시작점과 끝점만 변경해서 시간을 단축한다.
        public int turn(int focus) {
            return focus-1<0 ? 2*N-1 : focus-1;
        }

        // 로봇의 위치를 이동한다.
        public boolean move() {
            int focus = exit-1;

            // 가장 먼저 올라간 로봇부터 이동하므로 끝점부터 시작점 순으로 하나씩 이동한다.
            while(true) {
                int next = focus+1;
                if(focus < 0) focus = 2*N-1;

                // 현재 위치에 로봇이 있고 다음 위치에 로봇이 없으며 다음 위치의 내구도가 0 이상인 경우
                if(robot[focus] && !robot[next] && belt[next] > 0) {
                    robot[focus] = false;
                    if(next != exit)    robot[next] = true;
                    if(--belt[next] == 0)   K--;
                }

                // 끝점인 경우 반복문 탈출
                if(focus-- == enter)  break;
            }

            if(K <= 0)   return false;
            return true;
        }

        // 로봇을 새로 올린다.
        public boolean up() {
            // 시작점 위치의 내구도가 0 이상인 경우
            if(belt[enter] > 0) {
                robot[enter] = true;
                if(--belt[enter] == 0)   K--;
            }

            if(K <= 0)   return false;
            return true;
        }

        public int work() {
            int time = 0;

            // 시뮬레이션
            while(true) {
                time++;                 // 단계 증가
                enter = turn(enter);    // 시작점 위치 변경 (컨베이어 벨트 위치 변경)
                exit = turn(exit);      // 끝점 위치 변경 (컨베이어 벨트 위치 변경)
                robot[exit] = false;    // 마지막 위치의 로봇 제거
                if(!move()) break;      // 로봇 이동
                if(!up()) break;        // 로봇 새로 올리기
            }

            return time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] tempInfo = br.readLine().split(" ");
        int N = Integer.parseInt(tempInfo[0]);
        int K = Integer.parseInt(tempInfo[1]);

        Conveyor conveyor = new Conveyor(br.readLine().split(" "), N, K);
        System.out.println(conveyor.work());
    }
}