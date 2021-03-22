import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 포켓몬 번호 또는 이름을 통해 바로 정보를 조회할 수 있는 해시테이블과 배열
        HashMap<String, Integer> nameToNum = new HashMap<>();
        String[] numToName = new String[N+1];

        for(int i=1;i<=N;i++){
            String pocketmon = br.readLine();
            nameToNum.put(pocketmon, i);
            numToName[i] = pocketmon;
        }

        // Query 문
        while(M-- > 0){
            String query = br.readLine();
            // Query가 포켓몬 번호인 경우
            if(query.charAt(0) >= 48 && query.charAt(0) <= 57)
                sb.append(numToName[Integer.parseInt(query)]).append("\n");
            // Query가 포켓몬 이름인 경우
            else
                sb.append(nameToNum.get(query)).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}