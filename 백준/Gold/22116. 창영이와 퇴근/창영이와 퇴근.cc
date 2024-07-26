#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll a[N][N];
bool cache[N][N];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    ll l = -1, r = 1e15;

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        queue<pll> q; q.push({ 0, 0 }); 
        memset(cache, false, sizeof cache);
        cache[0][0] = true;
        while (!q.empty())
        {
            auto to = q.front(); q.pop();
            ll x = to.first, y = to.second;
            for (int k = 0; k < 4; k++)
            {
                ll nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (cache[nx][ny]) continue;
                ll d = abs(a[x][y] - a[nx][ny]);

                if (d <= mid)
                {
                    cache[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }

        if (cache[n - 1][n - 1]) r = mid;
        else l = mid;
    }

    cout << r;
}