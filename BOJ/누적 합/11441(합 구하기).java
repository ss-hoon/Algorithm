import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());

		int[] sum = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int idx=1; idx<=n; idx++) {
			sum[idx] = sum[idx-1] + Integer.parseInt(st.nextToken());
		}

		int test = Integer.parseInt(br.readLine());
		while (test-- > 0) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			sb.append(sum[end] - sum[start-1]).append('\n');
		}

		System.out.println(sb);
	}
}