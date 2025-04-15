#include <iostream>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;

        list<char> pw;
        auto cursor = pw.begin();

        for (char ch : input) {
            if (ch == '<') {
                if (cursor != pw.begin()) cursor--;
            } else if (ch == '>') {
                if (cursor != pw.end()) cursor++;
            } else if (ch == '-') {
                if (cursor != pw.begin()) cursor = pw.erase(--cursor);
            } else {
                pw.insert(cursor, ch);
            }
        }

        for (char c : pw) cout << c;
        cout << '\n';
    }
    return 0;
}
