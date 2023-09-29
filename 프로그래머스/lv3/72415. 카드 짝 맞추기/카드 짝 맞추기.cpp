#include <bits/stdc++.h>
using namespace std;
const int n = 4;
const int m = 4;
typedef pair<int, int> pii;
typedef long long ll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pii> v[10];
bool cache[10];
pii prv[10];
int x, y;
int ans = 1e9;

int bfs(int x1, int y1, int x2, int y2, vector<vector<int>> &a)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[x1][y1] = 0;
    queue<pii> q; q.push({ x1, y1 });
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] == -1)
            {
                q.push({ nx, ny });
                dist[nx][ny] = dist[x][y] + 1;
            }
            while (a[nx][ny] == 0)
            {
                nx += dx[i], ny += dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
                {
                    nx -= dx[i], ny -= dy[i];
                    break;
                }
            }
            if (dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    a[x2][y2] = 0;
    return dist[x2][y2] + 1;
}

void dfs(int idx, vector<vector<int>> &a)
{
    if (idx == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            int c = prv[i].first, k = prv[i].second;
            if (v[c].size() == 0) continue;
            if (k == 1) swap(v[c][0], v[c][1]);
        }
        
        vector<vector<int>> sa = a; 
        int cx = x, cy = y;
        int res = 0;
        for (int i = 0; i < 6; i++)
        {
            int c = prv[i].first;
            if (v[c].size() == 0) continue;
            for (int j = 0; j < 2; j++)
            {
                res += bfs(cx, cy, v[c][j].first, v[c][j].second, sa);
                cx = v[c][j].first, cy = v[c][j].second;
            }
        }
        
        for (int i = 0; i < 6; i++)
        {
            int c = prv[i].first, k = prv[i].second;
            if (v[c].size() == 0) continue;
            if (k == 1) swap(v[c][0], v[c][1]);
        }
        
        ans = min(ans, res);
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        if (cache[i]) continue;
        cache[i] = true;
        for (int j = 0; j < 2; j++)
        {
            prv[idx] = pii(i, j);
            dfs(idx + 1, a);
        }
        cache[i] = false;
    }
}

int solution(vector<vector<int>> a, int r, int c) 
{   
    x = r, y = c;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] != 0)
            v[a[i][j] - 1].push_back({ i, j });
    }
    
    dfs(0, a);
    
    return ans; 
}