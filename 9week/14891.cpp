#include <iostream>
#include <string>
#include <vector>

using namespace std;

string gears[4];

void rotate(int idx, int dir) {
    if (dir == 1) { // 시계 방향
        gears[idx] = gears[idx].back() + gears[idx].substr(0, 7);
    } else { // 반시계 방향
        gears[idx] = gears[idx].substr(1) + gears[idx][0];
    }
}

int main() {
    for (int i = 0; i < 4; ++i)
        cin >> gears[i];

    int k;
    cin >> k;
    while (k--) {
        int num, dir;
        cin >> num >> dir;
        --num;
        vector<int> rotateDir(4, 0);
        rotateDir[num] = dir;

        // 왼쪽 확인
        for (int i = num - 1; i >= 0; --i) {
            if (gears[i][2] != gears[i + 1][6])
                rotateDir[i] = -rotateDir[i + 1];
            else
                break;
        }

        // 오른쪽 확인
        for (int i = num + 1; i < 4; ++i) {
            if (gears[i - 1][2] != gears[i][6])
                rotateDir[i] = -rotateDir[i - 1];
            else
                break;
        }

        // 회전 적용
        for (int i = 0; i < 4; ++i) {
            if (rotateDir[i] != 0)
                rotate(i, rotateDir[i]);
        }
    }

    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (gears[i][0] == '1')
            score += (1 << i);
    }
    cout << score << endl;
    return 0;
}
