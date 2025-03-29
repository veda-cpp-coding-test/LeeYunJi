#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int str[9];
    int total = 0;

    for (int i = 0; i < 9; i++) {
        cin >> str[i];
        total += str[i];
    }

    sort(str, str + 9);  // 오름차순 정렬

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (total - (str[i] + str[j]) == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << str[k] << endl;
                    }
                }
                return 0; // 정답 찾으면 프로그램 종료
            }
        }
    }

    return 0;
}
