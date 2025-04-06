#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string N;
    cin >> N;

    int count[10] = {0};

    // 각 숫자 개수 세기
    for (char c : N) {
        int digit = c - '0';
        count[digit]++;
    }

    // 6과 9는 합쳐서 계산
    int sixNine = (count[6] + count[9] + 1) / 2;

    // count[6]과 count[9] 대신 sixNine 사용
    count[6] = sixNine;
    count[9] = sixNine;

    // 최대값이 필요한 세트 개수
    int result = *max_element(count, count + 10);

    cout << result << endl;
    return 0;
}
