#include <bits/stdc++.h>
using namespace std;
const int N = 300002;
int dist[N], mv[N];
vector<int> g[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int s, e; cin >> s >> e;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    memset(dist, -1, sizeof dist);
    queue<int> q; q.push(s); dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (v - 1 >= 1 && dist[v - 1] == -1)
        {
            q.push(v - 1);
            dist[v - 1] = dist[v] + 1;
        }
        if (v + 1 <= n && dist[v + 1] == -1)
        {
            q.push(v + 1);
            dist[v + 1] = dist[v] + 1;
        }
        for (auto nv : g[v])
        {
            if (dist[nv] == -1)
            {
                q.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }

    cout << dist[e];
}