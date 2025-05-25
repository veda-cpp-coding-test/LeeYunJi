#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int ROW = 12;
const int COL = 6;
char board[ROW][COL];
bool visited[ROW][COL];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bfs(int x, int y, vector<pair<int, int>>& group) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    char color = board[x][y];
    group.push_back({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL)
                continue;
            if (!visited[nx][ny] && board[nx][ny] == color) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                group.push_back({nx, ny});
            }
        }
    }
    return group.size() >= 4;
}

void applyGravity() {
    for (int col = 0; col < COL; ++col) {
        int emptyRow = ROW - 1;
        for (int row = ROW - 1; row >= 0; --row) {
            if (board[row][col] != '.') {
                char temp = board[row][col];
                board[row][col] = '.';
                board[emptyRow][col] = temp;
                --emptyRow;
            }
        }
    }
}

int main() {
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            cin >> board[i][j];

    int chain = 0;
    while (true) {
        bool popped = false;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (board[i][j] != '.' && !visited[i][j]) {
                    vector<pair<int, int>> group;
                    if (bfs(i, j, group)) {
                        popped = true;
                        for (auto [x, y] : group)
                            board[x][y] = '.';
                    }
                }
            }
        }
        if (!popped)
            break;
        applyGravity();
        ++chain;
    }
    cout << chain << endl;
    return 0;
}
