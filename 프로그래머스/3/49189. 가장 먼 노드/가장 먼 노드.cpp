#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 20002;
vector<int> g[N];
int dist[N];

int solution(int n, vi edge) 
{
    memset(dist, -1, sizeof dist);
    for (auto to : edge)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dist[1] = 0; queue<int> q; q.push(1);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int nv : g[v])
        {
            if (dist[nv] != -1) continue;
            q.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
    
    int mx = 0;
    
    for (int i = 1; i <= n; i++)
        mx = max(mx, dist[i]);
    
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == mx)
            ans++;
    }
    
    return ans;
}