#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 120;
ll a[N][N], dist[N][N][4];
ll n, t;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof dist);
    cin >> n >> t;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    priority_queue<pair<ll, tuple<ll, ll, ll>>> pq;
    pq.push({ 0, { 0, 0, 0 }}); dist[0][0][0] = 0;

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        ll w = -to.first;
        ll x = get<0>(to.second), y = get<1>(to.second), k = get<2>(to.second);
        if (dist[x][y][k] != w) continue;

        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            ll w = t + ((k + 1 == 3) ? a[nx][ny] : 0);
            if (dist[nx][ny][(k + 1) % 3] == -1 || dist[x][y][k] + w < dist[nx][ny][(k + 1) % 3])
            {
                dist[nx][ny][(k + 1) % 3] = dist[x][y][k] + w;
                pq.push({ -dist[nx][ny][(k + 1) % 3], { nx, ny, (k + 1) % 3 }});
            }
        }
    }

    ll ans = 1e18;

    for (int k = 0; k < 3; k++)
    {
        if (dist[n - 1][n - 1][k] == -1) continue;
        ans = min(ans, dist[n - 1][n - 1][k]);
    }

    cout << ans;
}