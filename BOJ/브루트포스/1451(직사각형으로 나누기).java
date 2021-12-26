import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    /** 직사각형 클래스 */
    static class Rectangle {
        int N, M;                   // 전체 직사각형의 세로 : N, 가로: M
        int[][] rectangle;          // 전체 직사각형 한 칸의 값
        long[][] runningTotal;      // 누적합
        long max = 0;               // 최대 합의 곱 크기

        /** 직사각형 클래스 생성자 */
        Rectangle(int N, int M) throws IOException {
            this.N = N;
            this.M = M;

            rectangle = new int[N+1][M+1];
            runningTotal = new long[N+1][M+1];

            // 한 칸의 값을 계산하면서 (1,1)부터 해당 값까지의 누적합을 계산
            for(int row=1; row<=N; row++) {
                String line = br.readLine();
                for(int col=1; col<=M; col++) {
                    rectangle[row][col] = line.charAt(col-1) - '0';
                    runningTotal[row][col] = runningTotal[row-1][col] + runningTotal[row][col-1] + rectangle[row][col] - runningTotal[row-1][col-1];
                }
            }
        }

        // 범위의 합 계산 (y1: 시작점 y값, x1: 시작점 x값, y2: 끝점 y값, x2: 끝점 x값)
        long getRange(int y1, int x1, int y2, int x2) {
            return runningTotal[y2][x2] - runningTotal[y1-1][x2] - runningTotal[y2][x1-1] + runningTotal[y1-1][x1-1];
        }

        // 직사각형 배치 방법 1 : 가로 3개
        void divide1() {
            for(int first=1; first<=N-2; first++) {
                for(int second=first+1; second<=N-1; second++) {
                    max = Math.max(max, getRange(1, 1, first, M) * getRange(first+1, 1, second, M) * getRange(second+1, 1, N, M));
                }
            }
        }

        // 직사각형 배치 방법 2 : 세로 3개
        void divide2() {
            for(int first=1; first<=M-2; first++) {
                for(int second=first+1; second<=M-1; second++) {
                    max = Math.max(max, getRange(1, 1, N, first) * getRange(1, first+1, N, second) * getRange(1, second+1, N, M));
                }
            }
        }

        // 직사각형 배치 방법 3 : 위쪽에 가로 1개, 아래쪽에 세로 2개
        void divide3() {
            for(int first=1; first<=N-1; first++) {
                for(int second=1; second<=M-1; second++) {
                    max = Math.max(max, getRange(1, 1, first, M) * getRange(first+1, 1, N, second) * getRange(first+1, second+1, N, M));
                }
            }
        }

        // 직사각형 배치 방법 4 : 왼쪽에 세로 1개, 오른쪽에 가로 2개
        void divide4() {
            for(int first=1; first<=M-1; first++) {
                for(int second=1; second<=N-1; second++) {
                    max = Math.max(max, getRange(1, 1, N, first) * getRange(1, first+1, second, M) * getRange(second+1, first+1, N, M));
                }
            }
        }

        // 직사각형 배치 방법 5 : 위쪽에 세로 2개, 아래쪽에 가로 1개
        void divide5() {
            for(int first=N; first>=2; first--) {
                for(int second=1; second<=M-1; second++) {
                    max = Math.max(max, getRange(first, 1, N, M) * getRange(1, 1, first-1, second) * getRange(1, second+1, first-1, M));
                }
            }
        }

        // 직사각형 배치 방법 6 : 왼쪽에 가로 2개, 오른쪽에 세로 1개
        void divide6() {
            for(int first=M; first>=2; first--) {
                for(int second=1; second<=N-1; second++) {
                    max = Math.max(max, getRange(1, first, N, M) * getRange(1, 1, second, first-1) * getRange(second+1, 1, N, first-1));
                }
            }
        }

        // 방법 1부터 6까지 중 최대값 구하기
        long getMax() {
            divide1();
            divide2();
            divide3();
            divide4();
            divide5();
            divide6();

            return max;
        }
    }

    public static void main(String[] args) throws IOException {
        String[] temp = br.readLine().split(" ");
        Rectangle rectangle = new Rectangle(Integer.parseInt(temp[0]), Integer.parseInt(temp[1]));
        System.out.println(rectangle.getMax());
    }
}