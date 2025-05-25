#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[6] = {0}; // 주사위의 6면: 위, 아래, 앞, 뒤, 왼, 오

// 동, 서, 북, 남
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 주사위를 굴리는 함수
void roll(int dir) {
    int temp = dice[0];
    switch(dir) {
        case 0: // 동
            dice[0] = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[5];
            dice[5] = temp;
            break;
        case 1: // 서
            dice[0] = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = temp;
            break;
        case 2: // 북
            dice[0] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[3];
            dice[3] = temp;
            break;
        case 3: // 남
            dice[0] = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[2];
            dice[2] = temp;
            break;
    }
}

int main() {
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> map[i][j];

    for(int i = 0; i < K; ++i) {
        int cmd;
        cin >> cmd;
        int dir = cmd - 1;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위를 벗어나면 무시
        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        roll(dir);
        x = nx;
        y = ny;

        if(map[x][y] == 0) {
            map[x][y] = dice[1];
        } else {
            dice[1] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }

    return 0;
}
