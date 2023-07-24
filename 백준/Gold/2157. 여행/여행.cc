#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 400;
int n, m, k;
ll dp[N][N];
vector<pll> g[N];

ll solve(int i, int c)
{
    if (i == n) return 0;
    ll &ret = dp[i][c];
    if (ret != -1) return ret;
    ret = -1e9;
    for (auto to : g[i])
    {
        int ni = to.first, w = to.second;
        if (ni < i) continue;
        if (ni == n || c > 1)
            ret = max(ret, solve(ni, c - 1) + w);
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    cout << solve(1, m - 1);
}