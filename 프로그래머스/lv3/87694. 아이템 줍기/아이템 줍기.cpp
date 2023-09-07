#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
const int N = 200;
int cache[N][N], road[N][N];
int dist[N][N];
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int solution(vi rect, int cX, int cY, int iX, int iY)
{
    int ans = 0;
    
    for (auto to : rect)
    {
        int x1 = to[0] * 2, y1 = to[1] * 2, x2 = to[2] * 2, y2 = to[3] * 2;
        for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++)
        {
            if (i == x1 || i == x2 || j == y1 || j == y2)
                cache[i][j] = 2;
        }
    }
    
    queue<pii> q; q.push({ 0, 0 });
    cache[0][0] = 1;
    
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        if (cache[x][y] == 2) continue;
        
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (cache[nx][ny] == 2)
            {
                road[nx][ny] = 1;
                continue;
            }
            else if (cache[nx][ny] == 0)
            {
                cache[nx][ny] = 1;
                q.push({ nx, ny });
            }
        }
    }
    
    memset(dist, -1, sizeof dist);
    dist[cX * 2][cY * 2] = 0; q.push({ cX * 2, cY * 2});
    
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        // cout << x << ' ' << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] == -1 && road[nx][ny]) 
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    
    return dist[iX * 2][iY * 2] / 2;
}