#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const ll N = 10002;
const ll inf = 987654321;
ll dp[N];

ll solve(int x)
{
    ll &ret = dp[x];
    if (ret != -1) return ret;
    if (x <= 2) return ret = 1;
    ret = 0;
    for (int i = 0; i < x; i += 2)
    {
        ll l = i, r = (x - 2) - i;
        if (l > r) break;
        ll lv = i + 1, rv = (-(i + 1) + x) % x;
        ll res = solve(i) * solve(r) % inf;
        if (lv != rv) res *= 2, res %= inf;
        ret += res, ret %= inf;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    ll n; cin >> n;
    cout << solve(n);
}