#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 100002;
int n;
vector<ll> g[N];
pll c[N];
ll dp[N][2];

ll solve(int v, int p, int k)
{
    ll &ret = dp[v][k];
    if (ret != -1) return ret;
    ret = (k == 0) ? c[v].first : c[v].second;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        ret += solve(nv, v, 1 - k);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        cin >> c[i].first >> c[i].second;

    cout << min(solve(0, -1, 0), solve(0, -1, 1));
}