import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static ArrayList<Student> frame = new ArrayList<>();

    static class Student implements Comparable<Student> {
        int seq, order, cnt;

        Student(int seq, int order, int cnt) {
            this.seq = seq;
            this.order = order;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Student s) {
            if (this.cnt == s.cnt) {
                return this.order - s.order;
            } else {
                return this.cnt - s.cnt;
            }
        }
    }

    static void plusRecommend(int seq) {
        for (Student student : frame) {
            if (student.seq == seq) {
                student.cnt++;
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] check = new boolean[101];

        N = Integer.parseInt(br.readLine());
        int recommend = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int idx=0; idx<recommend; idx++) {
            int student = Integer.parseInt(st.nextToken());

            if (frame.size() == N && !check[student]) {
                check[frame.get(0).seq] = false;
                frame.remove(0);
            }

            if (!check[student]) {
                check[student] = true;
                frame.add(new Student(student, idx, 1));
            } else {
                plusRecommend(student);
            }

            Collections.sort(frame);
        }

        StringBuilder sb = new StringBuilder();
        for (int idx=1; idx<=100; idx++) {
            if (check[idx]) sb.append(idx).append(' ');
        }

        System.out.println(sb);
    }
}