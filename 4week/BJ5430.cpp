#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string p;
        int n;
        string arr;

        cin >> p >> n >> arr;

        deque<int> dq;
        string num = "";
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;
            } else if (c == ',' || c == ']') {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        bool isReverse = false, error = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                isReverse = !isReverse;
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) cout << "error\n";
        else {
            cout << "[";
            while (!dq.empty()) {
                if (isReverse) {
                    cout << dq.back();
                    dq.pop_back();
                } else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
