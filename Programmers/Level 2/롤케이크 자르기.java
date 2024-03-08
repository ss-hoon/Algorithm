import java.util.HashSet;

class Solution {
    public int solution(int[] topping) {
        // 초기화
        int answer = 0;
        int[] left = new int[10001];
        int[] right = new int[10001];
        HashSet<Integer> leftTopping = new HashSet<>();
        HashSet<Integer> rightTopping = new HashSet<>();

        // 1. 모든 토핑을 오른쪽 토핑에 세팅
        for (int item : topping) {
            rightTopping.add(item);
            right[item]++;
        }

        // 2. 하나씩 잘라보면서 (오른쪽 제거, 왼쪽 추가) 왼쪽과 오른쪽 토핑 수를 확인하고 같으면 answer 증가
        for (int item : topping) {
            leftTopping.add(item);
            left[item]++;
            right[item]--;

            if (right[item] == 0) {
                rightTopping.remove(item);
            }

            if (leftTopping.size() == rightTopping.size()) {
                answer++;
            }
        }

        // 3. 공평하게 자르는 방법 반환
        return answer;
    }
}
