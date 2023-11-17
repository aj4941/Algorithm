#include <bits/stdc++.h>
using namespace std;
const int N = 150;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
int dist[N][N];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solution(vi a)
{
    memset(dist, -1, sizeof dist);
    int n = a.size(), m = a[0].size();
    queue<pii> q; q.push({ 0, 0 }); dist[0][0] = 1;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
    
    return dist[n - 1][m - 1];
}