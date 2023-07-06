#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 102;
ll dp[N][N * N];
int n, m, T, M;
vector<tuple<int, int, int>> g[N];

ll solve(int v, int ct)
{
    ll &ret = dp[v][ct];
    if (ret != -1) return ret;
    ret = 1e9;
    if (v == n) return ret = 0;

    for (auto to : g[v])
    {
        int nv = get<0>(to), t = get<1>(to), w = get<2>(to);
        if (ct + t <= T)
            ret = min(ret, solve(nv, ct + t) + w);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> T >> M;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, t, w; cin >> u >> v >> t >> w;
        g[u].push_back({ v, t, w });
        g[v].push_back({ u, t, w });
    }

    int ans = solve(1, 0);
    if (ans > M) ans = -1;
    cout << ans;
}