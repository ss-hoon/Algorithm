import java.io.*;

public class Main {
    private static boolean isPrime(int num) {
        if(num == 1)    return false;

        for(int idx=2; idx<=Math.sqrt(num); idx++) {
            if(num % idx == 0)  return false;
        }

        return true;
    }

    private static boolean isPalindrome(int num) {
        int originNum = num;
        if(num < 10)    return true;

        int reverseNum = 0;
        while(num > 0) {
            reverseNum *= 10;
            reverseNum += num % 10;
            num /= 10;
        }

        return reverseNum == originNum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(br.readLine());
        for(int idx=num; idx<=Integer.MAX_VALUE; idx++) {
            if(isPrime(idx) && isPalindrome(idx)) {
                System.out.println(idx);
                break;
            }
        }
    }
}