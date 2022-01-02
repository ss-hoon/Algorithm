import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Sudoku {

        int[][] board = new int[9][9];
        int count = 0;
        
        Sudoku() throws IOException {
            for(int row=0; row<9; row++) {
                String line = br.readLine();
                for(int col=0; col<9; col++) {
                    board[row][col] = line.charAt(col) - '0';
                    if(board[row][col] != 0)    count++;
                }
            }
        }

        boolean solve(int y, int x) {
            if(count == 81) {
                StringBuilder sb = new StringBuilder();
                for(int row=0; row<9; row++) {
                    for(int col=0; col<9; col++) {
                        sb.append(board[row][col]);
                    }
                    sb.append("\n");
                }
                System.out.println(sb);
                return true;
            }

            if(board[y][x] != 0) {
                if(x == 8) {
                    return solve(y + 1, 0);
                }
                else {
                    return solve(y, x + 1);
                }
            }

            for(int num=1; num<=9; num++) {
                if(!isCorrectRow(y, x, num) || !isCorrectCol(y, x, num) || !isCorrectSquare(y, x, num)) {
                    continue;
                }

                board[y][x] = num;
                count++;
                if(x == 8) {
                    if (solve(y + 1, 0)) return true;
                }
                else {
                    if (solve(y, x + 1)) return true;
                }
                board[y][x] = 0;
                count--;
            }
            return false;
        }

        boolean isCorrectRow(int y, int x, int num) {
            for(int col=0; col<9; col++) {
                if(col != x && num == board[y][col])    return false;
            }
            return true;
        }

        boolean isCorrectCol(int y, int x, int num) {
            for(int row=0; row<9; row++) {
                if(row != y && num == board[row][x])    return false;
            }
            return true;
        }

        boolean isCorrectSquare(int y, int x, int num) {
            int startY = y / 3;
            int startX = x / 3;

            for(int row=3*startY; row<3*startY+3; row++) {
                for(int col=3*startX; col<3*startX+3; col++) {
                    if(!(row == y && col == x) && board[row][col] == num)   return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) throws IOException {
        Sudoku sudoku = new Sudoku();
        sudoku.solve(0, 0);
    }
}