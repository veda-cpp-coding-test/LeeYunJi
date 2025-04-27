#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        if (st.empty()) ans++;
    }

    cout << ans;
    return 0;
}
