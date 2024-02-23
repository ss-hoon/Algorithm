class Solution {
    public int solution(int storey) {
        // 초기화
        int answer = 0;
        
        // 1. 뒷자리부터 계산 (올림/내림 중 어디에 가까운 지 찾고 올림에 가까운 경우 앞자리에 +1)
        while (storey > 0) {
            int num = storey % 10;
            int nextNum = storey % 100 / 10;
            
            if (num > 5 || (num == 5 && nextNum >= 5)) {
                storey += 10 - num;
                answer += 10 - num;
            } else {
                answer += num;
            }
            
            storey /= 10;
        }
        
        // 2. 결과 반환
        return answer;
    }
}
