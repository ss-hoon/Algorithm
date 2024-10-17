import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		ArrayList<ArrayList<int[]>> balls = new ArrayList<>(2001);
		int sum = 0;
		int[] colorSum = new int[200001];
		int[] result = new int[N];

		for (int idx=0; idx<=2000; idx++)
			balls.add(new ArrayList<>());

		for (int idx=0; idx<N; idx++) {
			String[] line = br.readLine().split(" ");
			int color = Integer.parseInt(line[0]);
			int weight = Integer.parseInt(line[1]);

			balls.get(weight).add(new int[] { idx, color });
		}

		for (int weight=1; weight<2001; weight++) {
			if (balls.get(weight).isEmpty())	continue;

			for (int[] ball : balls.get(weight))
				result[ball[0]] = sum - colorSum[ball[1]];

			for (int[] ball : balls.get(weight))
				colorSum[ball[1]] += weight;

			sum += weight * balls.get(weight).size();
		}

		for (int idx=0; idx<N; idx++)
			sb.append(result[idx]).append("\n");

		System.out.println(sb);
	}
}
