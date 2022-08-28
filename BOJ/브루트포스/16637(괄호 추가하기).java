import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, result = Integer.MIN_VALUE;
    static int[] num;
    static char[] operator;

    private static void calcMaxResult(int beforeResult, int pos) {
        if(pos >= N/2+1) {
            result = Math.max(result, beforeResult);
            return;
        }

        char oper = (pos == 0) ? '+' : operator[pos-1];

        // 괄호 치는 경우
        if(pos+1 < N/2+1) {
            int bracket = calculator(num[pos], num[pos + 1], operator[pos]);
            calcMaxResult(calculator(beforeResult, bracket, oper), pos + 2);
        }

        // 괄호 치지 않는 경우
        calcMaxResult(calculator(beforeResult, num[pos], oper), pos+1);
    }

    private static int calculator(int num1, int num2, char oper) {
        switch (oper) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            default:
                return Integer.MIN_VALUE;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        num = new int[N/2+1];
        operator = new char[N/2];

        char[] expression = br.readLine().toCharArray();
        for(int idx=0; idx<N; idx++) {
            if(idx % 2 == 0)
                num[idx/2] = expression[idx] - '0';
            else
                operator[idx/2] = expression[idx];
        }

        calcMaxResult(0, 0);
        System.out.println(result);
    }
}