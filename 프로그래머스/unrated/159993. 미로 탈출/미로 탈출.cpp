#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 200;
int dist[N][N];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

int bfs(pii st, pii ed, vector<string> &a)
{
    memset(dist, -1, sizeof dist);
    queue<pii> q; q.push(st);
    dist[st.first][st.second] = 0;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
    
    return dist[ed.first][ed.second];
}

int solution(vector<string> a)
{
    memset(dist, -1, sizeof dist);
    n = a.size(), m = a[0].size();
    pii s, e, l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'S') s = pii(i, j);
            if (a[i][j] == 'L') l = pii(i, j);
            if (a[i][j] == 'E') e = pii(i, j);
        }
    }
    
    int r1 = bfs(s, l, a);
    int r2 = bfs(l, e, a);
    if (r1 == -1 || r2 == -1) return -1;
    return r1 + r2;
}