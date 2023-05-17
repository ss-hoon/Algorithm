class Solution {
    public int[] solution(int[] sequence, int k) {
        int len = sequence.length;
        int[] answer = {0, 10000001};
        
        int left = 0;
        int right = -1;
        int sum = 0;
        while (right < len) {            
            if (sum < k && right+1 < len) {
                sum += sequence[++right];
            } else if (sum > k)   {
                sum -= sequence[left++];
            } else if (sum == k) {
                if (right - left < answer[1] - answer[0]) {
                    answer[0] = left;
                    answer[1] = right;
                }
                
                right++;
                if (right < len)
                    sum += sequence[right];
            } else {
                right++;
            }
        }
        
        return answer;
    }
}