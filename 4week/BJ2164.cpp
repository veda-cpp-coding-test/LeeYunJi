#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    while (q.size() > 1) {
        q.pop(); // 버림
        q.push(q.front()); // 다음은 뒤로
        q.pop();
    }

    cout << q.front();
    return 0;
}
