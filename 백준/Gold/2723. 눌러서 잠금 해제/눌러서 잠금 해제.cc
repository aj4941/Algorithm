#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 102;
ll dp[N][N];
ll n;
ll fac[N];
ll nCr[N][N];

ll comb(ll x, ll y)
{
    ll &ret = nCr[x][y];
    if (ret != -1) return ret;
    if (x == y || y == 0) return ret = 1;
    return ret = comb(x - 1, y) + comb(x - 1, y - 1);
}

ll solve(int i, int j)
{
    ll &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == 0 && j == 0) return ret = 1;
    if (i == 0 && j > 0) return ret = 0;
    ret = 0;
    if (j > 0)
    {
        for (int x = 1; x <= i; x++)
            ret += comb(i, x) * solve(i - x, j - 1);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(nCr, -1, sizeof nCr);
    ll t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ll ans = 0;
        memset(dp, -1, sizeof dp);
        for (int k = 1; k <= n; k++)
        {
            for (int j = 1; j <= k; j++)
            {
                ll res = solve(k, j) * comb(n, k);
                ans += res;
            }
        }
        cout << ans << "\n";
    }
}