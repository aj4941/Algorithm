#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 100002;
int n;
pii g[N];
ll dp[N];

ll solve(int x)
{
    ll &ret = dp[x];
    if (ret != -1) return ret;
    ret = 0;
    if (g[x].second != -1)
        ret = solve(g[x].second) + 1;

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u, l, r; cin >> u >> l >> r;
        g[u] = { l, r };
        if (l != -1) ans += 2;
        if (r != -1) ans += 2;
    }

    ans -= solve(1);

    cout << ans;
}