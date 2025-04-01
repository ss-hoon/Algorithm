import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] tokens = br.readLine().toCharArray();

        Stack<Character> quotes = new Stack<>();
        int value = 1;
        int answer = 0;

        for (int idx=0; idx<tokens.length; idx++) {
            char token = tokens[idx];

            switch (token) {
                case '(':
                    value *= 2;
                    quotes.push(token);
                    break;

                case '[':
                    value *= 3;
                    quotes.push(token);
                    break;

                case ')':
                    if (quotes.isEmpty() || quotes.peek() == '[') {
                        System.out.println(0);
                        return;
                    }

                    if (tokens[idx-1] == '(')
                        answer += value;

                    value /= 2;
                    quotes.pop();
                    break;

                case ']':
                    if (quotes.isEmpty() || quotes.peek() == '(') {
                        System.out.println(0);
                        return;
                    }

                    if (tokens[idx-1] == '[')
                        answer += value;

                    value /= 3;
                    quotes.pop();
                    break;
            }
        }

        System.out.println(quotes.isEmpty() ? answer : 0);
    }
}
