#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int dp[102][202];
bool f[222][222];
vector<int> a, g[222];
int N;

int solve(int i, int j)
{
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 1e9;
    
    if (i + 1 == N - 1)
    {
        if (f[j][a[i + 1]]) return ret = 0;
        else return ret = 1e9;
    }
    
    for (int nj : g[j])
    {
        if (nj == a[i + 1])
            ret = min(ret, solve(i + 1, nj));
        else
            ret = min(ret, solve(i + 1, nj) + 1);
    }
    
    return ret;
}

int solution(int n, int m, vi edge, int k, vector<int> log) 
{
    N = k; a = log;
    memset(dp, -1, sizeof dp);
    memset(f, false, sizeof f);
    for (int i = 0; i < 202; i++) g[i].clear();
    for (auto to : edge)
    {
        int u = to[0], v = to[1];
        if (f[u][v] == false)
        {
            g[u].push_back(v); g[v].push_back(u);
            f[u][v] = f[v][u] = true;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = true;
        g[i].push_back(i);
    }
    
    int ans = solve(0, a[0]);
    if (ans == 1e9) ans = -1;
    
    return ans;
}