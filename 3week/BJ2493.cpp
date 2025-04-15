#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> s; // (index, height)

    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;

        while (!s.empty() && s.top().second < height) s.pop();

        if (s.empty()) cout << 0 << " ";
        else cout << s.top().first << " ";

        s.push({i, height});
    }
    return 0;
}
