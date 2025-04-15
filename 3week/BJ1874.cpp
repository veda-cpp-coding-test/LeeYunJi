#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, num, idx = 1;
    cin >> n;

    stack<int> s;
    vector<char> result;

    for (int i = 0; i < n; i++) {
        cin >> num;
        while (idx <= num) {
            s.push(idx++);
            result.push_back('+');
        }
        if (s.top() == num) {
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for (char c : result) cout << c << '\n';
    return 0;
}
