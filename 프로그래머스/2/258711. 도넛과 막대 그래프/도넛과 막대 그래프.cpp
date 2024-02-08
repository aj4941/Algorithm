#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 1002000;
int indegree[N], outdegree[N];
vector<int> g[N];
bool cache[N];

void dfs(int v)
{
    cache[v] = true;
    for (int nv : g[v])
    {
        if (cache[nv]) continue;
        dfs(nv);
    }
}

vector<int> solution(vi edges) 
{
    int n = -1;
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        outdegree[u]++; indegree[v]++;
        n = max(n, max(u, v));
    }
    
    int pv = -1;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0 && outdegree[i] >= 2)
            pv = i;
    }
    
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        if (pv == u) 
        {
            outdegree[u]--;
            indegree[v]--;
            continue;
        }
        g[u].push_back(v);
    }
    
    int c1 = 0, c2 = 0, c3 = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (pv == i || cache[i]) continue;
        if (indegree[i] == 0 && outdegree[i] <= 1)
        {
            c2++;
            dfs(i);
        }
        if (indegree[i] == 2 && outdegree[i] == 2)
        {
            c3++;
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (pv == i || cache[i]) continue;
        c1++; dfs(i);
    }
    
    return { pv, c1, c2, c3 };
}