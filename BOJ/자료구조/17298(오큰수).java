import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int top = -1;
		int N = Integer.parseInt(br.readLine());
		int[] array = new int[N];
		int[] stack = new int[N];
		int[] nges = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int idx=0; idx<N; idx++)
			array[idx] = Integer.parseInt(st.nextToken());

		for (int idx=N-1; idx>=0; idx--) {
			while (top >= 0) {
				if (array[idx] < stack[top]) {
					nges[idx] = stack[top];
					stack[++top] = array[idx];
					break;
				}

				top--;
			}

			if (top == -1) {
				stack[++top] = array[idx];
				nges[idx] = -1;
			}
		}

		StringBuilder result = new StringBuilder();
		for (int nge : nges)
			result.append(nge).append(' ');

		System.out.println(result);
	}
}
