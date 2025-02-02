import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		int result = 1;
		int N = Integer.parseInt(br.readLine());
		int[][] meeting = new int[N][2];

		for (int idx=0; idx<N; idx++) {
			String[] line = br.readLine().split(" ");

			meeting[idx][0] = Integer.parseInt(line[0]);
			meeting[idx][1] = Integer.parseInt(line[1]);
		}

		Arrays.sort(meeting, (o1, o2) -> o1[0] - o2[0]);

		pq.add(meeting[0][1]);
		for (int idx=1; idx<N; idx++) {
			int start = meeting[idx][0];
			int end = meeting[idx][1];

			if (start < pq.peek())
				result++;
			else
				pq.poll();

			pq.add(end);
		}

		System.out.println(result);
	}
}
