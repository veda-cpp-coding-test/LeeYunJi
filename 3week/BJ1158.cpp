#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    vector<int> result;
    int idx = 0;
    while (!v.empty()) {
        idx = (idx + k - 1) % v.size();
        result.push_back(v[idx]);
        v.erase(v.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ">";
    return 0;
}
