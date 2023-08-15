#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1020;
int a[N][N], dist[N][N];
int n, m, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    cin >> k;
    vector<pii> tmp;
    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        tmp.push_back({ x, y });
    }

    memset(dist, -1, sizeof dist);
    queue<pii> q;

    for (int j = 0; j < m; j++)
    {
        if (a[0][j] == 1)
        {
            q.push({ 0, j });
            dist[0][j] = 0;
        }
    }

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int i = 0; i < tmp.size(); i++)
        {
            int nx = x + tmp[i].first, ny = y + tmp[i].second;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] != -1 || a[nx][ny] == 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    int ans = 1e9;
    for (int j = 0; j < m; j++)
    {
        if (dist[n - 1][j] != -1)
            ans = min(ans, dist[n - 1][j]);
    }

    if (ans == 1e9) ans = -1;
    cout << ans;
}