#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int str[6];
    int total = 0;
    for (int i = 0; i < 5; i++){
        cin >> str[i];
        total += str[i];
    }
    cout << total / 5 << endl;
    sort(str, str+5);
    cout << str[2] << endl;

    return 0;
}