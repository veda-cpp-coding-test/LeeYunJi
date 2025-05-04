#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (int i : graph[v])
    {
        if (!visited[i])
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i : graph[cur])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        sort(graph[i].begin(), graph[i].end());

    dfs(start);
    cout << '\n';
    fill(visited, visited + n + 1, false);
    bfs(start);
    return 0;
}
