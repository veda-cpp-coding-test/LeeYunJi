#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int result = A * B * C;

    // 각 숫자(0~9)가 등장한 횟수를 저장할 배열
    int count[10] = {0};

    // 숫자를 문자열로 변환하여 각 문자 순회
    string str = to_string(result);
    for (char c : str) {
        count[c - '0']++;  // 해당 숫자 위치에 +1
    }

    // 출력
    for (int i = 0; i < 10; i++) {
        cout << count[i] << '\n';
    }

    return 0;
}
