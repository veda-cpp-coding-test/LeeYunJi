#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int visited[301][301];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int l, sx, sy, ex, ey;
        cin >> l >> sx >> sy >> ex >> ey;

        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visited[sx][sy] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == ex && y == ey) {
                cout << visited[x][y] - 1 << '\n';
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return 0;
}
