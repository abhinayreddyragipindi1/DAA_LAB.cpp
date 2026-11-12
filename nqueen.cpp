
#include <iostream>
#include <vector>
using namespace std;

int n, count = 0;
vector<int> board;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        count++;
        cout << "\nSolution " << count << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
            board[row] = -1;
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    board.assign(n, -1);

    solve(0);

    if (count == 0)
        cout << "No solution exists.";

    cout << "\nTotal solutions: " << count;
    return 0;
}
