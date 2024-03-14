
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
import java.util.PriorityQueue;
import java.util.ArrayList;

class Solution {
    public int solution(int k, int n, int[][] reqs) {
        // 초기화
        int answer = 0, totalMento = k;
        int[] mento = new int[k+1];
        int[] waitTime = new int[k+1];
        ArrayList<int[]>[] consulting = new ArrayList[k+1];

        for (int idx=1; idx<=k; idx++) {
            consulting[idx] = new ArrayList<>();
        }

        // 1. 상담 요청을 유형별로 분리한다.
        for (int[] request : reqs) {
            consulting[request[2]].add(request);
        }

        // 2. 기본으로 멘토 1명씩 붙이고 각 유형의 대기 시간을 구한다.
        for (int idx=1; idx<=k; idx++) {
            mento[idx] = 1;
            waitTime[idx] = getWaitTime(1, consulting[idx]);
        }

        while (totalMento < n) {

            // 3. 각 유형에 멘토 1명씩 더 붙일 때, 대기 시간을 많이 줄일 수 있는 유형 번호를 구한다.
            int diff = -1, target = 0;
            for (int idx=1; idx<=k; idx++) {
                int plusMentoWaitTime = waitTime[idx] - getWaitTime(mento[idx] + 1, consulting[idx]);

                if (diff < plusMentoWaitTime) {
                    diff = plusMentoWaitTime;
                    target = idx;
                }
            }

            // 4. 대기 시간을 많이 줄일 수 있는 유형 번호에 멘토 1명을 추가한다.
            mento[target]++;
            waitTime[target] -= diff;
            totalMento++;
        }

        // 5. 각 유형의 대기 시간을 모두 합하고 반환한다.
        for (int idx=1; idx<=k; idx++)      answer += waitTime[idx];

        return answer;
    }

    // 대기 시간 반환 메서드
    private int getWaitTime(int mento, ArrayList<int[]> consulting) {
        if (consulting.isEmpty() || consulting.size() <= mento)   return 0;

        PriorityQueue<Integer> finishTime = new PriorityQueue<>();
        int waitTime = 0;

        for (int idx=0; idx<mento; idx++) {
            finishTime.add(0);
        }

        for (int[] consult : consulting) {
            int nextFinishTime = finishTime.poll();

            if (consult[0] < nextFinishTime)   waitTime += (nextFinishTime - consult[0]);

            finishTime.add(Math.max(nextFinishTime, consult[0]) + consult[1]);
        }

        return waitTime;
    }
}
