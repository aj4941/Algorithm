#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 500;
vector<pii> g[N];
int dist[N][N];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = 1e9;
        }
    }
    
    for (auto to : fares)
    {
        for (auto too : to)
        {
            int u = to[0], v = to[1], w = to[2];
            dist[u][v] = dist[v][u] = w;
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
            if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
    
    int ans = 1e9;
    
    for (int x = 1; x <= n; x++)
    {
        if (dist[s][x] == 1e9) continue;
        if (dist[x][a] == 1e9 || dist[x][b] == 1e9) continue;
        ans = min(ans, dist[s][x] + dist[x][a] + dist[x][b]);
    }
    
    return ans;
}