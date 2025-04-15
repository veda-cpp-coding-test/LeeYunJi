#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, num;
    cin >> k;

    stack<int> s;
    while (k--) {
        cin >> num;
        if (num == 0 && !s.empty()) s.pop();
        else s.push(num);
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}
