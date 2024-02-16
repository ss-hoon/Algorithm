class Solution {
    public int solution(String[] board) {
        int answer = 1;
        int[] count = new int[2]; // 0: O, 1: X
        int[] successCnt = new int[2];
        int[] rowSum = new int[3];
        int[] colSum = new int[3];
        int leftCrossSum = 0;
        int rightCrossSum = 0;
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int value = 0;
                if (board[i].charAt(j) == 'O')  value = 1;
                else if (board[i].charAt(j) == 'X') value = -1;
                
                if (value == 1)  count[0]++;
                if (value == -1) count[1]++;
                
                rowSum[i] += value;
                colSum[j] += value;
                
                if (i == j) 
                    leftCrossSum += value;
                
                if (Math.abs(i - j) == 2 || (i == 1 && j == 1))
                    rightCrossSum += value;
            }
        }
        
        for (int i=0; i<3; i++) {
            if (rowSum[i] == 3 || colSum[i] == 3)         successCnt[0]++;
            else if (rowSum[i] == -3 || colSum[i] == -3)  successCnt[1]++;
        }
        
        if (leftCrossSum == 3 || rightCrossSum == 3)      successCnt[0]++;
        if (leftCrossSum == -3 || rightCrossSum == -3)    successCnt[1]++;
        
        // O가 X보다 1개 많거나 같아야한다. (둘의 차이는 2 이상이면 안된다)
        if (count[0] < count[1] || Math.abs(count[0] - count[1]) > 1) {
            answer = 0;
        }
        
        // O가 1개 많은 경우 무승부이거나 O가 이겨야한다
        if (count[0] == count[1] + 1 && successCnt[1] > 0) {
            answer = 0;
        }
        
        // O와 X가 같은 경우 무승부이거나 X가 이겨야한다
        if (count[0] == count[1] && successCnt[0] > 0) {
            answer = 0;
        }
        
        return answer;
    }
}
