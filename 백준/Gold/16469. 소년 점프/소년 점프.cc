#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 200;
int n, m;
string s[N];
int dist[3][N][N];
int cnt[N * N];

void bfs(int x, int y, int dist[N][N])
{
    queue<pii> q; q.push({ x, y }); dist[x][y] = 0;
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (s[nx][ny] == '1') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < 3; i++)
    {
        memset(dist[i], -1, sizeof dist[i]);
        int x, y; cin >> x >> y;
        bfs(x - 1, y - 1, dist[i]);
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        int mx = 0;
        bool flag = true;
        for (int c = 0; c < 3; c++)
        {
            if (dist[c][i][j] == -1)
            {
                flag = false;
                break;
            }
            mx = max(mx, dist[c][i][j]);
        }

        if (flag) cnt[mx]++;
    }

    for (int i = 1; i < N * N; i++)
    {
        if (cnt[i] > 0)
        {
            cout << i << "\n" << cnt[i];
            return 0;
        }
    }

    cout << -1;
}