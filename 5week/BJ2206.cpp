#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
char map[1001][1001];
int visited[1001][1001][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Node {
    int x, y, wall;
};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        auto [x, y, wall] = q.front();
        q.pop();

        if (x == n-1 && y == m-1) {
            cout << visited[x][y][wall];
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (map[nx][ny] == '0' && visited[nx][ny][wall] == 0) {
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                    q.push({nx, ny, wall});
                } else if (map[nx][ny] == '1' && wall == 0 && visited[nx][ny][1] == 0) {
                    visited[nx][ny][1] = visited[x][y][wall] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }

    cout << -1;
    return 0;
}
