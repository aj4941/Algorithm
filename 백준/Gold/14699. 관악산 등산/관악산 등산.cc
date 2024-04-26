#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 5002;
int n, m;
int h[N], dp[N];
vector<int> g[N];

int solve(int v)
{
    int &ret = dp[v];
    if (ret != -1) return ret;
    ret = 1;
    for (int nv : g[v])
    {
        if (h[v] < h[nv])
            ret = max(ret, solve(nv) + 1);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        cout << solve(i) << "\n";
    }
}