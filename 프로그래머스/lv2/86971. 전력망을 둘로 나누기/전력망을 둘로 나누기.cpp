#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 200;
vector<int> g[N];

int dfs(int v, int p)
{
    int res = 1;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        res += dfs(nv, v);
    }
    return res;
}

int solution(int n, vi wires) 
{
    for (auto to : wires)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int ans = 1e9;
    
    for (int i = 1; i <= n; i++)
    {
        for (int ni : g[i])
        {
            int res = dfs(ni, i);
            // cout << i << ' ' << ni << ' ' << n - res << endl;
            int r1 = n - res, r2 = res;
            ans = min(ans, abs(r1 - r2));
        }
    }
    
    return ans;
}