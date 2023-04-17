import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static char[][] fields = new char[12][6];
	static boolean[][] visited = new boolean[12][6];
	static Queue<int[]> puyoList;
	static int[] dy = {-1, 0, 0, 1};
	static int[] dx = {0, -1, 1, 0};

	static int cntSamePuyo(int y, int x, char puyo) {
		if (y < 0 || y >= 12 || x < 0 || x >= 6 || visited[y][x] || fields[y][x] != puyo) return 0;

		int cnt = 0;
		visited[y][x] = true;
		puyoList.add(new int[]{y, x});
		for (int idx=0; idx<4; idx++) {
			int Y = y + dy[idx];
			int X = x + dx[idx];

			cnt += cntSamePuyo(Y, X, puyo);
		}

		return cnt + 1;
	}

	static void explodePuyo() {
		while (!puyoList.isEmpty()) {
			int[] pos = puyoList.poll();

			int y = pos[0];
			int x = pos[1];

			fields[y][x] = '.';
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int idx=0; idx<12; idx++) {
			fields[idx] = br.readLine().toCharArray();
		}

		int result = 0;
		while (true) {

			// 초기화 작업
			visited = new boolean[12][6];
			int cntExplode = 0;

			// 1. 이중 for문으로 터트릴 수 있는 뿌요 search (위에서부터 아래로)
			for (int i=0; i<12; i++) {
				for (int j=0; j<6; j++) {
					puyoList = new LinkedList<>();

					if (!visited[i][j] && fields[i][j] != '.' && cntSamePuyo(i, j, fields[i][j]) >= 4) {
						explodePuyo();
						cntExplode++;
					}

					puyoList.clear();
				}
			}

			// 2. 모두 터트린 후, 모든 뿌요들을 아래로 옮긴다.
			for (int j=0; j<6; j++) {
				for (int i=11; i>=0; i--) { // 뿌요 search
					if (fields[i][j] != '.') {
						for (int k=11; k>i; k--) { // 빈 공간 search
							if (fields[k][j] == '.') {
								int diff = k-i;
								for (int l=i; l>=0; l--) { // 밑으로 내릴 뿌요들
									fields[l+diff][j] = fields[l][j];
									fields[l][j] = '.';
								}
								break;
							}
						}
					}
				}
			}

			// 3. 다시 1번부터 진행하고 터트릴 뿌요가 없다면 종료한다.
			if (cntExplode == 0) {
				break;
			} else {
				result++;
			}
		}

		System.out.println(result);
	}
}