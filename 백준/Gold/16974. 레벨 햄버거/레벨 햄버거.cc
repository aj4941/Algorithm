#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pll dp[52];
ll ans = 0;

void solve(ll n, ll x)
{
    if (x == 0) return;
    if (n == 0)
    {
        ans += 1;
        return;
    }
    vector<ll> a = { 0, dp[n - 1].first, 1, dp[n - 1].first, 0 };
    vector<ll> b = { 1, dp[n - 1].second, 1, dp[n - 1].second, 1 };
    ll val = 0;

    for (int i = 0; i < 5; i++)
    {
        if (val + b[i] > x)
        {
            solve(n - 1, x - val);
            return;
        }
        else
        {
            ans += a[i];
            val += b[i];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    dp[0].first = 1, dp[0].second = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i].first = 1 + 2 * dp[i - 1].first;
        dp[i].second = 3 + 2 * dp[i - 1].second;
    }

    solve(n, x);
    cout << ans;
}