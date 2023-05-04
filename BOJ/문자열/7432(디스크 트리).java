import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static class Trie {
		TrieNode rootNode;

		Trie() {
			rootNode = new TrieNode();
		}

		void insert(String[] path) {
			TrieNode node = rootNode;

			for (String directory : path) {
				if (!node.childNodes.containsKey(directory)) {
					node.childNodes.put(directory, new TrieNode());
				}

				node = node.childNodes.get(directory);
			}
		}

		void print(TrieNode node, String in) {
			if (node.childNodes.size() == 0) return;

			for (String key : node.childNodes.keySet()) {
				sb.append(in).append(key).append("\n");
				print(node.childNodes.get(key), in + " ");
			}
		}
	}

	static class TrieNode {
		TreeMap<String, TrieNode> childNodes = new TreeMap<>();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Trie trie = new Trie();
		int N = Integer.parseInt(br.readLine());

		while (N-- > 0) {
			trie.insert(br.readLine().split("\\\\"));
		}

		trie.print(trie.rootNode, "");
		System.out.println(sb);
	}
}
