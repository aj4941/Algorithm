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

const int N = 2000;
int a[N][N], dist[N][N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    int k; cin >> k;
    vector<pii> pos;
    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        pos.push_back({ x, y });
    }

    queue<pii> q;
    memset(dist, -1, sizeof dist);

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

        for (auto to : pos)
        {
            int nx = x + to.first, ny = y + to.second;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    int ans = 1e9;
    for (int j = 0; j < m; j++)
    {
        if (dist[n - 1][j] == -1) continue;
        ans = min(ans, dist[n - 1][j]);
    }

    if (ans == 1e9) ans = -1;
    
    cout << ans;
}