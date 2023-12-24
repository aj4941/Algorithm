#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
const int N = 500 * 500 + 10;
int p[N], sz[N];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

bool merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return false;
    p[x] = y, sz[y] += sz[x], sz[x] = 0;
    return true;
}

int solution(vi a) 
{
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n * m; i++) 
    {
        p[i] = i;
        sz[i] = 1;
    }
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == 1)
        {
            int sz = 1;
            queue<pii> q; q.push({ i, j });
            while (!q.empty())
            {
                auto to = q.front(); q.pop();
                int x = to.first, y = to.second;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (a[nx][ny] == 1)
                    {
                        if (merge(nx * m + ny, i * m + j))
                            q.push({ nx, ny });
                    }
                }
            }
            
        }
    }
    
    int ans = 0;
    
    for (int j = 0; j < m; j++)
    {
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 1)
            {
                int x = find(i * m + j);
                if (mp.count(x)) continue;
                mp[x] = 1, res += sz[x];
            }
        }
        ans = max(ans, res);
    }
    
    return ans; 
}