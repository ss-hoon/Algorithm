import java.io.*;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        PriorityQueue<Integer> leftMaxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> rightMinHeap = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());
        int root = Integer.parseInt(br.readLine());
        sb.append(root).append("\n");

        for(int i=1;i<N;i++){
            int num = Integer.parseInt(br.readLine());
            if(leftMaxHeap.size() < rightMinHeap.size()){
                if(root < num){
                    leftMaxHeap.add(root);
                    if(!rightMinHeap.isEmpty() && rightMinHeap.peek() < num){
                        rightMinHeap.offer(num);
                        root = rightMinHeap.poll();
                    }
                    else root = num;
                }
                else leftMaxHeap.offer(num);
            }
            else{
                if(root < num)  rightMinHeap.offer(num);
                else{
                    rightMinHeap.offer(root);
                    if(!leftMaxHeap.isEmpty() && leftMaxHeap.peek() > num){
                        leftMaxHeap.offer(num);
                        root = leftMaxHeap.poll();
                    }
                    else root = num;
                }
            }
            sb.append(root).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}