#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 600;
int n, m;
int board[N][N], dist[N][N];

void calc(int x1, int y1, int x2, int y2, int val)
{
    for (int i = min(x1, x2); i <= max(x1, x2); i++)
    {
        for (int j = min(y1, y2); j <= max(y1, y2); j++)
            board[i][j] = val;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // 위험
        calc(x1, y1, x2, y2, 1);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // 죽음
        calc(x1, y1, x2, y2, 2);
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        dist[i][j] = 1e9;

    deque<pii> q; q.push_back({ 0, 0 });
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto to = q.front(); q.pop_front();
        int x = to.first, y = to.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > 500 || ny > 500) continue;
            if (board[nx][ny] == 2) continue;
            if (board[nx][ny] == 0)
            {
                if (dist[nx][ny] > dist[x][y] + board[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + board[nx][ny];
                    q.push_front({ nx, ny });
                }
            }
            else
            {
                if (dist[nx][ny] > dist[x][y] + board[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + board[nx][ny];
                    q.push_back({nx, ny});
                }
            }
        }
    }

    int ans = dist[500][500];
    if (ans == 1e9) ans = -1;
    cout << ans;
}