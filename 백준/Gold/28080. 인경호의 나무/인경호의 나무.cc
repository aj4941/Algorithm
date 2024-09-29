#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll N = 2002;
const ll inf = 1000000007;
ll n, m;
ll a[N], dp[N][N];
vector<ll> g[N], res;

void solve(int v)
{
    if (g[v][0] != -1) solve(g[v][0]);
    res.push_back(a[v]);
    if (g[v][1] != -1) solve(g[v][1]);
}

ll nCr(ll n, ll r)
{
    ll &ret = dp[n][r];
    if (ret != -1) return ret;
    if (n == r || r == 0) return ret = 1;
    return ret = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % inf;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    res.push_back(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll l, r; cin >> l >> r;
        g[i].push_back(l); g[i].push_back(r);
    }

    solve(1); res.push_back(m + 1);

    ll ans = 1, cnt = 0;
    ll l = -1, r = -1;

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == -1) cnt++;
        else
        {
            if (cnt == 0) l = res[i];
            else
            {
                r = res[i];
                ll len = (r - 1) - (l + 1) + 1;
                ans *= nCr(len, cnt);
                ans %= inf; cnt = 0;
                l = res[i], r = -1;
            }
        }
    }

    cout << ans;
}