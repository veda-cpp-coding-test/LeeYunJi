#include <iostream>
#include <list>
using namespace std;

int main() {
    string str;
    cin >> str;

    list<char> editor(str.begin(), str.end());
    auto cursor = editor.end();

    int m;
    cin >> m;
    while (m--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor != editor.begin()) cursor--;
        } else if (cmd == 'D') {
            if (cursor != editor.end()) cursor++;
        } else if (cmd == 'B') {
            if (cursor != editor.begin()) editor.erase(--cursor);
        } else if (cmd == 'P') {
            char c;
            cin >> c;
            editor.insert(cursor, c);
        }
    }

    for (char c : editor) cout << c;
    return 0;
}
