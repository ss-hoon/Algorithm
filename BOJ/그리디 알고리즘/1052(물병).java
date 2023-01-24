import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		StringBuilder sb = new StringBuilder();
		while(N > 0) {
			sb.append(N % 2);
			N /= 2;
		}

		String binary = sb.reverse().toString();
		int cntOne = 0;
		int result = 0;
		int pivot = 0;
		for(int idx=0; idx<binary.length(); idx++) {
			char token = binary.charAt(idx);
			if(token == '1') {
				cntOne++;

				if(cntOne > K) {
					result += (int) Math.pow(2, binary.length() - idx - 1);
				} else if(cntOne == K) {
					pivot = binary.length() - idx - 1;
				}
			}
		}

		System.out.println(result != 0 ? (int) Math.pow(2, pivot) - result : 0);
	}
}
