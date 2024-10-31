import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] snacks = new int[N];
		int left = 0, right = Integer.MAX_VALUE;

		for (int idx=0; idx<N; idx++)
			snacks[idx] = Integer.parseInt(st.nextToken());

		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int count = 0;

			for (int snack : snacks)
				count += snack / mid;

			if (count < M)
				right = mid;
			else
				left = mid;
		}

		System.out.println(left);
	}
}
