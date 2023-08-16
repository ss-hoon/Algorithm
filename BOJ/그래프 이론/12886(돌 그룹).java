import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] stones = br.readLine().split(" ");

		boolean[][] visited = new boolean[1501][1501];
		Queue<int[]> que = new LinkedList<>();

		int a = Integer.parseInt(stones[0]);
		int b = Integer.parseInt(stones[1]);
		int c = Integer.parseInt(stones[2]);
		int sum = a + b + c;

		if (sum % 3 == 0) {
			que.add(new int[] { a, b });
			visited[a][b] = true;
		}

		while (!que.isEmpty()) {
			int[] current = que.poll();
			int first = current[0];
			int second = current[1];
			int[] temp = { first, second, sum - first - second };

			for (int i=0; i<3; i++) {
				for (int j=0; j<3; j++) {
					if (temp[i] < temp[j]) {
						int num1 = temp[i] * 2;
						int num2 = temp[j] - temp[i];

						if (!visited[num1][num2]) {
							que.add(new int[] { num1, num2 });
							visited[num1][num2] = true;
						}
					}
				}
			}
		}

		System.out.println(visited[sum/3][sum/3] ? "1" : "0");
	}
}