#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
char map[1001][1001];
int fire[1001][1001], person[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> w >> h;
        queue<pair<int,int>> fq, pq;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                fire[i][j] = person[i][j] = 0;
                if (map[i][j] == '*') fq.push({i, j});
                if (map[i][j] == '@') pq.push({i, j});
            }
        }

        while (!fq.empty()) {
            auto [x, y] = fq.front();
            fq.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (!fire[nx][ny] && map[nx][ny] != '#') {
                        fire[nx][ny] = fire[x][y] + 1;
                        fq.push({nx, ny});
                    }
                }
            }
        }

        bool escaped = false;
        while (!pq.empty() && !escaped) {
            auto [x, y] = pq.front();
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << person[x][y] + 1 << '\n';
                    escaped = true;
                    break;
                }
                if (!person[nx][ny] && map[nx][ny] == '.' &&
                    (fire[nx][ny] == 0 || fire[nx][ny] > person[x][y] + 1)) {
                    person[nx][ny] = person[x][y] + 1;
                    pq.push({nx, ny});
                }
            }
        }

        if (!escaped) cout << "IMPOSSIBLE\n";
    }
    return 0;
}
