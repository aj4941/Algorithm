#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 2002;
ll dp[N][N][2];
ll n;
vector<ll> a;

ll solve(int x, int y, int c)
{
    ll &ret = dp[x][y][c];
    if (ret != -1) return ret;
    ret = 0;
    if (x == y)
    {
        if (c == 1) return ret = 0;
        else return ret = a[x];
    }
    if (c == 0)
    {
        ret = max(ret, solve((x + 1) % n, y, 1 - c) + a[x]);
        ret = max(ret, solve(x, (y - 1 + n) % n, 1 - c) + a[y]);
    }
    else
    {
        if (a[y] < a[x])
            ret = solve((x + 1) % n, y, 1 - c);
        else
            ret = solve(x, (y - 1 + n) % n, 1 - c);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, solve((i + 1) % n, (i - 1 + n) % n, 1) + a[i]);

    cout << ans;
}