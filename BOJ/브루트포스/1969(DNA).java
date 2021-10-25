import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int hammingDistance = 0;

        // 입력
        String[] tempInfo = br.readLine().split(" ");
        int N = Integer.parseInt(tempInfo[0]);
        int M = Integer.parseInt(tempInfo[1]);
        String[] dnaList = new String[N];

        for(int input=0; input<N; input++) {
            dnaList[input] = br.readLine();
        }

        // 문자열 비교 (그리디 알고리즘)
        // 가장 많이 속해있는 알파벳을 채택합니다.
        for(int idx=0; idx<M; idx++) {
            int[] alpha = new int[26];
            int maxComp = 0;
            int maxIdx = 0;

            // A부터 Z까지의 알파벳을 0부터 26까지의 배열 인덱스로 변환 후 카운팅합니다.
            for(String dna : dnaList) {
                alpha[dna.charAt(idx) - 'A']++;
            }

            // 같을 때는 사전 순이기에 A부터 Z 순으로 비교합니다.
            // 수가 클 때는 maxComp에 값을 넣고 해당 인덱스를 저장하고
            // 수가 같거나 작을 때는 무시합니다.
            for(int comp=0; comp<26; comp++) {
                if(maxComp < alpha[comp]) {
                    maxComp = alpha[comp];
                    maxIdx = comp;
                }
            }

            // 최대로 카운팅된 수는 해당 인덱스 라인에 있는 문자열들 중 동일한 알파벳의 개수이므로
            // 전체 문자열 수에서 최대로 카운팅된 수를 뺀 값을 hammingDistance에 추가합니다.
            hammingDistance += (N - maxComp);
            
            // 앞서 저장한 인덱스를 다시 알파벳으로 치환해 StringBuilder에 삽입합니다.
            sb.append((char)(maxIdx + 'A'));
        }

        // 출력
        System.out.println(sb.toString());
        System.out.println(hammingDistance);
        br.close();
    }
}