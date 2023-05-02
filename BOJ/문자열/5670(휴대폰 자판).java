import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

	static class Trie {
		TrieNode rootNode;

		Trie() {
			rootNode = new TrieNode();
		}

		void insert(String word) {
			TrieNode node = rootNode;

			for (char token : word.toCharArray()) {
				if (!node.childNodes.containsKey(token)) {
					node.childNodes.put(token, new TrieNode());
				}

				node = node.childNodes.get(token);
			}

			node.check = true;
		}

		int find(String word) {
			TrieNode node = rootNode;
			int cnt = 0;

			for (int idx=0; idx<word.length(); idx++) {
				char token = word.charAt(idx);

				if (idx == 0 || node.childNodes.size() > 1 || node.check) {
					cnt++;
				}

				node = node.childNodes.get(token);
			}

			return cnt;
		}
	}
	static class TrieNode {
		HashMap<Character, TrieNode> childNodes = new HashMap<>();
		boolean check = false;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String N;
		while ((N = br.readLine()) != null) {
			Trie trie = new Trie();
			int len = 0;

			String[] words = new String[100000];
			for (int idx=0; idx<Integer.parseInt(N); idx++) {
				words[idx] = br.readLine();
				trie.insert(words[idx]);
				len++;
			}

			int sum = 0;
			for (int idx=0; idx<len; idx++) {
				sum += trie.find(words[idx]);
			}

			sb.append(String.format("%.2f\n", (double) sum / len));
		}

		System.out.println(sb);
	}
}
