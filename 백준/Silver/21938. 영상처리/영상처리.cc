#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll a[1200][1200];
bool cache[1200][1200];
ll n, m;

void dfs(int x, int y)
{
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (cache[nx][ny] || a[nx][ny] == 0) continue;
        cache[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<ll> v;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        ll x, y, z; cin >> x >> y >> z;
        a[i][j] = (x + y + z) / 3;
    }
    ll t; cin >> t;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        a[i][j] = (a[i][j] >= t) ? 255 : 0;

    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (!cache[i][j] && a[i][j] == 255)
        {
            cache[i][j] = true;
            dfs(i, j); ans++;
        }
    }

    cout << ans;
}
