#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 300002;
int par[N], indegree[N];
vector<int> g[N];

void dfs(int v, int p)
{
    par[v] = p; indegree[p]++;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dfs(nv, v);
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    vector<ll> A;
    for (auto to : a) A.push_back(to);
    int n = a.size();
    
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    
    if (sum != 0)
        return -1;
    
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v); g[v].push_back(u);
    }
    
    dfs(0, n);
    
    queue<int> q;
    
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0) // leaf
            q.push(i);
    }
    
    ll ans = 0;
    
    while (!q.empty())
    {
        int v = q.front(); q.pop(); 
        int nv = par[v]; indegree[nv]--;
        ans += abs(A[v]);
        A[nv] += A[v]; A[v] = 0;
        if (indegree[nv] == 0)
            q.push(nv);
    }

    return ans;
}