import java.io.*;

public class Main {
    // 플레이어의 카드
    public static String[] cardList;
    // 최고점
    public static int maxScore;
    // 최고점인 플레이어
    public static int maxScorePlayer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 플레이어 수 입력
        int player = Integer.parseInt(br.readLine());

        // 플레이어가 가지고 있는 카드를 입력 받고
        // 모든 경우의 수 탐색 (완전 탐색)
        for(int order=1; order<=player; order++) {
            cardList = br.readLine().split(" ");
            maxScoreSearch(order, 0, 0, 0);
        }

        // 가장 높은 점수를 가진 플레이어 출력
        System.out.println(maxScorePlayer);
    }

public static void maxScoreSearch(int player, int cur, int cnt, int sum) {
        // 재귀 기저조건 : 카드 3장을 확인한 경우
        if(cnt == 3) {
            // 현재 최고점과 동일하거나 더 큰 경우
            // 최고점과 최고점 플레이어를 갱신
            // 동일한 최고점도 봐야하는 이유 : "이긴 사람이 두 명 이상일 경우에는 번호가 가장 큰 사람의 번호를 출력"
            if(maxScore <= (sum % 10)) {
                maxScore = (sum % 10);
                maxScorePlayer = player;
            }
            return;
        }

        // 1-2 2-1은 똑같은 경우이기에 한번만 검색하도록 순서를 만들어준다.
        for(int idx=cur; idx<5; idx++) {
            maxScoreSearch(player,idx+1, cnt+1, sum+Integer.parseInt(cardList[idx]));
        }
    }
}