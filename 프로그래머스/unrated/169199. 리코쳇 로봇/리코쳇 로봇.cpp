#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pii res[102][102][4];
int dist[102][102];

int solution(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    int px = -1, py = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R') px = i, py = j;
            if (board[i][j] == 'G') ex = i, ey = j;
            for (int k = 0; k < 4; k++)
            {
                res[i][j][k] = pii(-1, -1);
                if (board[i][j] == 'D') continue;
                int x = i, y = j;
                while (true)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'D') 
                    {
                        res[i][j][k] = pii(x, y);
                        break;
                    }
                    x = nx, y = ny;
                }
            }
        }
    }
    
    memset(dist, -1, sizeof dist);
    queue<pii> q; q.push({ px, py }); dist[px][py] = 0;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        // cout << "pos : " << x << ' ' << y << ' ' << dist[x][y] << endl;
        for (int k = 0; k < 4; k++)
        {
            int nx = res[x][y][k].first, ny = res[x][y][k].second;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
    
    return dist[ex][ey];
}