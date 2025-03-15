import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	private static class Node {
		Node front;
		char data;
		Node back;

		Node(Node front, char data, Node back) {
			this.front = front;
			this.data = data;
			this.back = back;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Node head = new Node(null, '\0', null);
		Node cursor = head;
		for (char token : br.readLine().toCharArray()) {
			cursor.back = new Node(cursor, token, null);
			cursor = cursor.back;
		}

		int M = Integer.parseInt(br.readLine());
		while (M-- > 0) {
			char[] operator = br.readLine().toCharArray();

			switch (operator[0]) {
				case 'P':
					Node insertNode = new Node(cursor, operator[2], cursor.back);

					if (cursor.back != null) {
						cursor.back.front = insertNode;
					}

					cursor.back = insertNode;
					cursor = cursor.back;
					break;

				case 'L':
					if (cursor.front != null) {
						cursor = cursor.front;
					}
					break;

				case 'D':
					if (cursor.back != null) {
						cursor = cursor.back;
					}
					break;

				case 'B':
					if (cursor != head) {
						if (cursor.back != null) {
							cursor.back.front = cursor.front;
						}

						cursor.front.back = cursor.back;
						cursor = cursor.front;
					}

					break;
			}
		}

		Node node = head.back;
		StringBuilder result = new StringBuilder();
		while (node != null) {
			result.append(node.data);
			node = node.back;
		}

		System.out.println(result);
	}
}
