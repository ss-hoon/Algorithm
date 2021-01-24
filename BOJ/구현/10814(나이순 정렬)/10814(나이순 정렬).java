import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    static class Member implements Comparable<Member>{
        int age;
        String name;
        int idx;

        Member(int age, String name, int idx) {
            this.age = age;
            this.name = name;
            this.idx = idx;
        }

        @Override
        public int compareTo(Member o) {
            if(this.age < o.age) return -1;
            else if(this.age > o.age)    return 1;
            else{
                if(this.idx < o.idx) return -1;
                else return 1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ArrayList<Member> list = new ArrayList<Member>();
        int N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++){
            String[] buf = br.readLine().split(" ");
            Member m = new Member(Integer.parseInt(buf[0]), buf[1], i);
            list.add(m);
        }
        Collections.sort(list);

        for(Member m : list){
            bw.write(m.age + " " + m.name + "\n");
        }
        bw.flush();
    }
}