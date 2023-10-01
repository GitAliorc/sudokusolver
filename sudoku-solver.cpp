#include <iostream>
using namespace std;

const int N = 9;

class SudokuSolver {
public:
    SudokuSolver(int grid[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                this->grid[i][j] = grid[i][j];
            }
        }
    }

    void solve() {
        if (solveSudoku()) {
            cout << "Solved Sudoku:" << endl;
            printSudoku();
        } else {
            cout << "No solution exists." << endl;
        }
    }

private:
    int grid[N][N];

    void printSudoku() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isSafe(int row, int col, int num) {
        for (int x = 0; x < N; x++) {
            if (grid[row][x] == num || grid[x][col] == num) {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudoku() {
        int row, col;
        bool isEmpty = false;
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == 0) {
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) {
                break;
            }
        }

        if (!isEmpty) {
            return true;
        }

        for (int num = 1; num <= 9; num++) {
            if (isSafe(row, col, num)) {
                grid[row][col] = num;
                if (solveSudoku()) {
                    return true;
                }
                grid[row][col] = 0;
            }
        }

        return false;
    }
};

int main() {
    int grid[N][N];
    cout << "Inserisci il sudoku(usa 0 per le celle vuote):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    SudokuSolver solver(grid);
    solver.solve();

    return 0;
}