#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int board[302][302], cache[302][302], lose[302][302];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

void dfs(int x, int y)
{
    cache[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
        if (!cache[cx][cy] && board[cx][cy] > 0)
            dfs(cx, cy);
    }
}

void func(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
        if (board[cx][cy] == 0)
            lose[x][y]++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    int ans = 0;
    while (true)
    {
        ans++;
        memset(lose, 0, sizeof lose);
        memset(cache, 0, sizeof cache);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] > 0)
                    func(i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                board[i][j] = max(0, board[i][j] - lose[i][j]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!cache[i][j] && board[i][j] > 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            cout << 0;
            return 0;
        }
        if (cnt > 1)
        {
            cout << ans;
            return 0;
        }
    }
}