#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    deque<int> dq;

    for (int i = 1; i <= n; i++) dq.push_back(i);

    while (m--) {
        int target;
        cin >> target;

        int idx = 0;
        for (; idx < dq.size(); idx++) {
            if (dq[idx] == target) break;
        }

        if (idx < dq.size() - idx) {
            while (dq.front() != target) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } else {
            while (dq.front() != target) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }

        dq.pop_front(); // 제거
    }

    cout << cnt;
    return 0;
}
