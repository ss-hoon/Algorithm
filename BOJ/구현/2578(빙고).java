import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int[] row = new int[5];
		int[] col = new int[5];
		int[] cross = new int[2];
		HashMap<Integer, int[]> board = new HashMap<>();
		for(int i=0; i<5; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<5; j++) {
				board.put(Integer.parseInt(st.nextToken()), new int[] {i, j});
			}
		}

		boolean isEnd = false;
		int result = 0, cntBingo = 0;
		while(!isEnd) {
			st = new StringTokenizer(br.readLine());

			while(st.hasMoreTokens()) {
				int num = Integer.parseInt(st.nextToken());

				int[] target = board.get(num);
				int posY = target[0];
				int posX = target[1];
				result++;

				row[posY]++;
				col[posX]++;
				if(posY == posX)		cross[0]++;
				if(posY + posX == 4)	cross[1]++;

				if(row[posY] == 5)	cntBingo++;
				if(col[posX] == 5)	cntBingo++;
				if(posY == posX && cross[0] == 5)	cntBingo++;
				if(posY + posX == 4 && cross[1] == 5)	cntBingo++;

				if(cntBingo >= 3){
					isEnd = true;
					break;
				}
			}
		}

		System.out.println(result);
	}
}
