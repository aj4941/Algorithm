#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 100;
int f[N][N];

int solution(int n, vi road, int K) 
{
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        if (i != j)
            f[i][j] = 1e9;
    }
    
    for (auto to : road)
    {
        int u = to[0], v = to[1], w = to[2];
        f[u][v] = min(f[u][v], w);
        f[v][u] = min(f[v][u], w);
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (f[i][k] == 1e9 || f[k][j] == 1e9) continue;
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (f[1][i] <= K) 
            ans++;
    }
    
    return ans;
}