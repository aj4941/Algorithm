#include <bits/stdc++.h>
using namespace std;
typedef queue<int> qi;
typedef vector<int> vi;
const int MAX = 1005;

bool visited[MAX];
vi graph[MAX];

void dfs(int v)
{
    visited[v] = true;
    cout << v << ' ';
    for (int i : graph[v])
    {
        if (!visited[i])
            dfs(i);
    }
}

void bfs(int v)
{
    qi queue = qi();
    queue.push(v);
    visited[v] = true;
    
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        cout << node << ' ';
        for (int i : graph[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

int n, m, v = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(visited, false, sizeof visited);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int st, en = 0;
        cin >> st >> en;
        graph[st].push_back(en);
        graph[en].push_back(st);
    }
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    dfs(v); cout << '\n';
    memset(visited, false, sizeof visited);
    bfs(v); cout << '\n';
}