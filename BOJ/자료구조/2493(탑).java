import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	private static class Tower {
		int height, idx;

		public Tower (int height, int idx) {
			this.height = height;
			this.idx = idx;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder result = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int[] height = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int idx=0; idx<N; idx++)
			height[idx] = Integer.parseInt(st.nextToken());

		Tower[] frontTower = new Tower[N+1];
		int top = 0;
		for (int idx=0; idx<N; idx++) {
			while (top > 0 && frontTower[top].height < height[idx])
				top--;

			if (top == 0)
				result.append(0).append(' ');
			else
				result.append(frontTower[top].idx).append(' ');

			frontTower[++top] = new Tower(height[idx], idx+1);
		}

		System.out.println(result);
	}
}
