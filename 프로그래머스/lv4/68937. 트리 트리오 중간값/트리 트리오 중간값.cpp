#include <bits/stdc++.h>
using namespace std;
int mx, mx_v, mx_cnt;
const int N = 250020;
vector<int> g[N];

void dfs(int v, int p, int len)
{
    if (mx < len)
    {
        mx = len; mx_v = v;
        mx_cnt = 1;
    }
    else if (mx == len)
    {
        mx_v = v;
        mx_cnt++;
    } 
    
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dfs(nv, v, len + 1);
    }
}

int solution(int n, vector<vector<int>> edges) {
    
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, -1, 0); 
    mx_cnt = 0;
    
    dfs(mx_v, -1, 0); 
    if (mx_cnt >= 2) return mx;
    
    mx_cnt = 0;
    
    dfs(mx_v, -1, 0);
    if (mx_cnt >= 2) return mx;
    
    return mx - 1;
}