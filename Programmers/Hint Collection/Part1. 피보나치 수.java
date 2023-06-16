class Solution {
    public int solution(int n) {
        int[] cache = new int[n+1];
        cache[1] = 1;
        
        for (int idx=2; idx<=n; idx++) {
            cache[idx] = (cache[idx-1] + cache[idx-2]) % 1234567;
        }
        
        return cache[n];
    }
}
