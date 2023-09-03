#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
vector<int> g[N];
int dp[N][2];

int solve(int x, int p, int c)
{
    // cout << x << ' ' << c << endl;
    int &ret = dp[x][c];
    if (ret != -1) return ret;
    ret = (c == 0) ? 0 : 1;
    int res = 0;
    
    for (int nx : g[x])
    {
        int tmp = 1e9;
        if (nx == p) continue;
        tmp = min(tmp, solve(nx, x, 1));
        if (c == 1)
            tmp = min(tmp, solve(nx, x, 0));
        
        res += tmp;
    }
    
    ret += res;
    return ret;
}

int solution(int n, vector<vector<int>> tmp) 
{

    memset(dp, -1, sizeof dp);
    for (auto to : tmp)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int r1 = solve(1, 0, 0);
    int r2 = solve(1, 0, 1);
    // cout << r1 << ' ' << r2 << endl;
    return min(solve(1, 0, 0), solve(1, 0, 1));
}