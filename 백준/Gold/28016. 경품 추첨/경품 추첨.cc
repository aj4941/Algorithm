#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tll;
const int N = 102;
pll dp[N][N][N];
ll a[N][N];
ll n, m, pos;

void solve(int x, int y)
{
    if (dp[x][y][1].first != -1)
        return;

    for (int i = 1; i <= m; i++)
        dp[x][y][i] = pll(0, 0);

    if (x == n)
    {
        dp[x][y][y] = pll(0, 1);
        return;
    }

    if (a[x + 1][y] == 0)
    {
        solve(x + 1, y);
        for (int i = 1; i <= m; i++)
        {
            dp[x][y][i].first += dp[x + 1][y][i].first * 2;
            dp[x][y][i].second += dp[x + 1][y][i].second * 2;
            dp[x][y][i].first += dp[x][y][i].second / (ll)1e18;
            dp[x][y][i].second %= (ll)1e18;
        }
    }
    else
    {
        if (a[x][y - 1] == 0 && a[x + 1][y - 1] == 0)
        {
            solve(x + 1, y - 1);
            for (int i = 1; i <= m; i++)
            {
                dp[x][y][i].first += dp[x + 1][y - 1][i].first;
                dp[x][y][i].second += dp[x + 1][y - 1][i].second;
                dp[x][y][i].first += dp[x][y][i].second / (ll)1e18;
                dp[x][y][i].second %= (ll)1e18;
            }
        }
        if (a[x][y + 1] == 0 && a[x + 1][y + 1] == 0)
        {
            solve(x + 1, y + 1);
            for (int i = 1; i <= m; i++)
            {
                dp[x][y][i].first += dp[x + 1][y + 1][i].first;
                dp[x][y][i].second += dp[x + 1][y + 1][i].second;
                dp[x][y][i].first += dp[x][y][i].second / (ll)1e18;
                dp[x][y][i].second %= (ll)1e18;
            }
        }
    }
}

bool cmp(pll &a, pll &b)
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second < b.second;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
        for (int k = 1; k < N; k++) dp[i][j][k] = pll(-1, -1);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 2) pos = j;
    }

    ll ans = -1;
    pll val = pll(0, 0); solve(1, pos);

    for (int i = 1; i <= m; i++)
    {
        if (cmp(val, dp[1][pos][i]))
        {
            val = dp[1][pos][i];
            ans = i - 1;
        }
    }

    cout << ans;
}