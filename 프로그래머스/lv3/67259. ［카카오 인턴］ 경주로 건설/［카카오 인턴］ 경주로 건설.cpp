#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef tuple<int, int, int, int> ti;
const int N = 50;
int dist[N][N][5];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solution(vi a) 
{
    int n = a.size(), m = a[0].size();
    memset(dist, -1, sizeof dist);
    priority_queue<ti> pq;
    
    for (int k = 0; k < 4; k++)
    {
        dist[0][0][k] = 0;
        pq.push({ 0, 0, 0, k });
    }
    
    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        int d = -get<0>(to);
        int x = get<1>(to), y = get<2>(to), c = get<3>(to);
        if (dist[x][y][c] != d) continue;
        
        for (int k = 0; k < 4; k++)
        {
            int w = (c == k) ? 100 : 600;
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 1) continue;
            if (dist[nx][ny][k] == -1 || dist[x][y][c] + w < dist[nx][ny][k])
            {
                dist[nx][ny][k] = dist[x][y][c] + w;
                pq.push({ -dist[nx][ny][k], nx, ny, k });
            }
        }
    }

    int ans = 1e9;
    
    for (int k = 0; k < 4; k++)
    {
        if (dist[n - 1][n - 1][k] == -1) continue;
        ans = min(ans, dist[n - 1][n - 1][k]);
    }
    
    return ans;
}