#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0, temp = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            temp *= 2;
            st.push('(');
        } else if (s[i] == '[') {
            temp *= 3;
            st.push('[');
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '(') ans += temp;
            st.pop();
            temp /= 2;
        } else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '[') ans += temp;
            st.pop();
            temp /= 3;
        }
    }

    if (!st.empty()) cout << 0;
    else cout << ans;
    
    return 0;
}
