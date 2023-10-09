#include <bits/stdc++.h>
using namespace std;
const int N = 102;
typedef vector<vector<int>> vi;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dist[N][N][5];
int n, m;

struct Node {
    int cnt, x, y, d;
};

bool check(int x1, int y1, int x2, int y2, vi &a)
{
    if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) return false;
    if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) return false;
    // if (x1 == x2 && y1 == y2) return false;
    if (a[x1][y1] || a[x2][y2]) return false;
    // cout << "check : " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    return true;
}

bool finish(int x1, int y1, int x2, int y2)
{
    if (x1 == n - 1 && y1 == m - 1) return true;
    if (x2 == n - 1 && y2 == m - 1) return true;
    return false;
}

int solution(vi a) 
{
    n = a.size(), m = a[0].size();
    queue<Node> q; 
    dist[0][0][0] = dist[0][1][2] = 1;
    q.push({ 0, 0, 0, 0 }); q.push({ 0, 0, 1, 2 });
    
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int cnt = to.cnt, x1 = to.x, y1 = to.y, d = to.d;
        
        // cout << cnt << ' ' << x1 << ' ' << y1 << ' ' << d << endl;
        int x2 = x1 + dx[d], y2 = y1 + dy[d];
        // cout << "nxt : " << x2 << ' ' << y2 << endl;

        if (finish(x1, y1, x2, y2))
            return cnt;
        
        for (int k = 0; k < 4; k++)
        {
            int nx1 = x1 + dx[k], ny1 = y1 + dy[k];
            int nx2 = nx1 + dx[d], ny2 = ny1 + dy[d];
            if (!check(nx1, ny1, nx2, ny2, a)) continue;
            cout << "ok" << endl;
            if (dist[nx1][ny1][d] == 0)
            {
                dist[nx1][ny1][d] = 1;
                q.push({ cnt + 1, nx1, ny1, d });
            }
                
            if (dist[nx2][ny2][(d + 2) % 4] == 0)
            {
                dist[nx2][ny2][(d + 2) % 4] = 1;
                q.push({ cnt + 1, nx2, ny2, (d + 2) % 4 });
            }
        }
        
        for (int k = 0; k < 4; k++) 
        {
            if (k == (d + 1) % 4 || k == (d + 3) % 4) // 90도 방향
            {
                int nx1 = x1 + dx[k], ny1 = y1 + dy[k];
                // cout << x1 << ' ' << y1 << endl;
                // cout << "nx1 : " << nx1 << ' ' << "ny1 : " << ny1 << endl;
                if (!check(x1, y1, nx1, ny1, a)) continue;
                // cout << "ok2" << endl;
                int cx = x2 + dx[k], cy = y2 + dy[k];
                
                if (cx < 0 || cy < 0 || cx >= n || cy >= m || a[cx][cy] == 1) 
                    continue;
                
                if (dist[x1][y1][k] == 0)
                {
                    dist[x1][y1][k] = 1;
                    q.push({ cnt + 1, x1, y1, k });
                }
                
                if (dist[nx1][ny1][(k + 2) % 4] == 0)
                {
                    dist[nx1][ny1][(k + 2) % 4] = 1;
                    q.push({ cnt + 1, nx1, ny1, (k + 2) % 4 });
                }
            }
        }
    }
} 