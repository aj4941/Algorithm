#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dist[120][120];
vector<pii> v;
int m, n, t;

pii calc(int c, int a)
{
    if (c == 1) return { 0, a };
    if (c == 2) return { n, a };
    if (c == 3) return { a, 0 };
    if (c == 4) return { a, m };
}

int solve(int x1, int y1, int x2, int y2)
{
    memset(dist, -1, sizeof dist);
    dist[x1][y1] = 0;
    queue<pii> q; q.push({ x1, y1 });
    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx == 0 || nx == n || ny == 0 || ny == m)
            {
                if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    return dist[x2][y2];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> t;
    for (int i = 0; i < t; i++)
    {
        int c, a; cin >> c >> a;
        v.push_back(calc(c, a));
    }

    int c, a; cin >> c >> a;
    pii res = calc(c, a);
    int x = res.first, y = res.second;

    ll ans = 0;

    for (int tc = 0; tc < t; tc++)
    {
        int res = 1e9;
        int cx = v[tc].first, cy = v[tc].second;
        ans += solve(x, y, cx, cy);
    }

    cout << ans;
}