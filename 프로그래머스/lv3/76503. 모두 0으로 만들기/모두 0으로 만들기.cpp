#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
const int N = 300005;
vector<int> g[N];
int par[N], indegree[N];

void dfs(int v, int p)
{
    par[v] = p;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        indegree[v]++;
        dfs(nv, v);
    }
}

ll solution(vector<int> A, vi edges) 
{
    vector<ll> a;
    int n = A.size();
    for (int i = 0; i < n; i++) 
        a.push_back(A[i]);
    
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v); g[v].push_back(u);
    }
    
    dfs(0, -1);
    queue<int> q;
    vector<bool> cache(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            cache[i] = true;
        }
    }
    
    ll ans = 0;
    
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int nv : g[v])
        {
            if (cache[nv]) continue;
            indegree[nv]--;
            ans += abs(a[v]);
            a[nv] += a[v], a[v] = 0;
            if (indegree[nv] == 0)
            {
                q.push(nv);
                cache[nv] = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            return -1;
    }
    
    return ans;
}