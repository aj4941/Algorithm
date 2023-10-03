#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
const int N = 500;
vector<pii> g[N];
int dist[N][N];

int solution(int n, int s, int a, int b, vi fares)
{
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        if (i != j)
            dist[i][j] = 1e9;
    }
    
    for (auto to : fares)
    {
        int u = to[0], v = to[1], w = to[2];
        dist[u][v] = dist[v][u] = w;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    
    int ans = 1e9;
    
    for (int i = 1; i <= n; i++)
    {
        if (dist[s][i] == 1e9 || dist[i][a] == 1e9 || dist[i][b] == 1e9) continue;
        int res = dist[s][i] + dist[i][a] + dist[i][b];
        ans = min(ans, res);
    }
    
    return ans;
}