#include <bits/stdc++.h>
using namespace std;
const int N = 20002;
vector<int> g[N];
int dist[N];

int solution(int n, vector<vector<int>> edge) {
    
    for (auto to : edge)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v); g[v].push_back(u);
    }
    
    memset(dist, -1, sizeof dist);
    queue<int> q; q.push(1); dist[1] = 0;
    int len = 0, cnt = 0;
    
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (len < dist[v])
        {
            len = dist[v];
            cnt = 1;
        }
        else if (len == dist[v])
        {
            cnt++;
        }
        for (int nv : g[v])
        {
            if (dist[nv] == -1)
            {
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }
    
    return cnt;
}