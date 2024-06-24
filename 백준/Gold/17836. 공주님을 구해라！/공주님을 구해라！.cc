#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

ll gcd(ll x, ll y) {
    return ((y) ? gcd(y, x % y) : x);
}

const int N = 200;
int dist[N][N][2], a[N][N];
int n, m, t;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof dist);
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    memset(dist, -1, sizeof dist);
    queue<tuple<int, int, int>> q; q.push({ 0, 0, 0 });
    dist[0][0][0] = 0;

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = get<0>(to), y = get<1>(to), c = get<2>(to);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny][c] != -1) continue;
            if (c == 0 && a[nx][ny] == 1) continue;
            int nc = (a[nx][ny] == 2) ? 1 : c;

            dist[nx][ny][nc] = dist[x][y][c] + 1;
            q.push({ nx, ny, nc });
        }
    }

    int r1 = (dist[n - 1][m - 1][0] == -1) ? 1e9 : dist[n - 1][m - 1][0];
    int r2 = (dist[n - 1][m - 1][1] == -1) ? 1e9 : dist[n - 1][m - 1][1];

    int ans = min(r1, r2);

    if (ans > t) cout << "Fail";
    else cout << ans;
}