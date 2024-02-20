class Solution {
     public long solution(int[] weights) {
        long answer = 0;    
        int[] people = new int[1001];
        int[] seesaw = new int[4001];

        for (int weight : weights) {
            int twoMulti = weight * 2;
            int threeMulti = weight * 3;
            int fourMulti = weight * 4;

            answer += seesaw[twoMulti]++;
            answer += seesaw[threeMulti]++;
            answer += seesaw[fourMulti]++;

            if (people[weight] > 0) {
                answer -= people[weight] * 2;
            }

            people[weight]++;
        }

        return answer;
    }
}
