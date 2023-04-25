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

        void insert(String[] road) {
            TrieNode node = rootNode;

            for (int idx=1; idx<road.length; idx++) {
                if (!node.childNodes.containsKey(road[idx])) {
                    node.childNodes.put(road[idx], new TrieNode());
                }

                node = node.childNodes.get(road[idx]);
            }
        }

        void print(TrieNode node, StringBuilder sub) {
            for (String key : node.childNodes.keySet()) {
                sb.append(sub).append(key).append("\n");

                sub.append("--");
                print(node.childNodes.get(key), sub);
                sub.delete(sub.length()-2, sub.length());
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
            trie.insert(br.readLine().split(" "));
        }

        trie.print(trie.rootNode, new StringBuilder());
        System.out.println(sb);
    }
}
