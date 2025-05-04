#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int order[100001], idx[100001];
bool visited[100001];
int cnt = 1;
bool flag = true;

void dfs(int v)
{
    visited[v] = true;
    if (order[cnt++] != v)
    {
        flag = false;
        return;
    }
    sort(graph[v].begin(), graph[v].end(), [](int a, int b)
         { return idx[a] < idx[b]; });
    for (int i : graph[v])
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> order[i];
        idx[order[i]] = i;
    }
    if (order[1] != 1)
    {
        cout << 0;
        return 0;
    }
    dfs(1);
    cout << flag;
    return 0;
}
