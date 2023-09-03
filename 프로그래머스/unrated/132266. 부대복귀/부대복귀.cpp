#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int dist[N];
vector<int> g[N];

vector<int> solution(int n, vector<vector<int>> r, vector<int> s, int d)
{
    vector<int> ans;
    for (auto to : r)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (auto to : s)
    {
        memset(dist, -1, sizeof dist);
        dist[to] = 0;
        queue<int> q; q.push(to);
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (int nv : g[v])
            {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
        
        ans.push_back(dist[d]);
    }
    
    return ans;
}