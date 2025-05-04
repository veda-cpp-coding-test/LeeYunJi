#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int order = 1;

void dfs(int v)
{
    visited[v] = order++;
    for (int i : graph[v])
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        sort(graph[i].begin(), graph[i].end());
    dfs(r);
    for (int i = 1; i <= n; ++i)
        cout << visited[i] << '\n';
    return 0;
}
