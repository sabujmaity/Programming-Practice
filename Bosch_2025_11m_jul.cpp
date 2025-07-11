#include <iostream>
#include <vector>
using namespace std;

// Directions: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int nRows, int nCols) {
    visited[x][y] = true;
    int cnt = 1; // Count current cell

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // Check bounds and conditions
        if (nx >= 0 && ny >= 0 && nx < nRows && ny < nCols &&
            !visited[nx][ny] && board[nx][ny] == 'O') {
            cnt += dfs(board, visited, nx, ny, nRows, nCols);
        }
    }
    return cnt;
}

int canReach(vector<vector<char>>& board, int nRows, int nCols) {
    if (board[0][0] == 'X') return 0;
    vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
    return dfs(board, visited, 0, 0, nRows, nCols);
}

int main() {
    int nRows, nCols;
    cin >> nRows >> nCols;
    vector<vector<char>> board(nRows, vector<char>(nCols));
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            cin >> board[i][j];
        }
    }
    cout << canReach(board, nRows, nCols) << endl;
    return 0;
}
