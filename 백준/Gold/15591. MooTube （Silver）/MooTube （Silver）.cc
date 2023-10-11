#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
const ll N = 8005;
vector<pll> g[N];
ll dist[N][N];

void dfs(ll v, ll p, ll st)
{
    for (auto to : g[v])
    {
        ll nv = to.first, w = to.second;
        if (nv == p) continue;
        dist[st][nv] = min(dist[st][v], w);
        dfs(nv, v, st);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dist, -1, sizeof dist);
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    for (ll i = 1; i <= n; i++)
    {
        dist[i][i] = 1e12;
        dfs(i, 0, i);
    }

    for (ll i = 0; i < q; i++)
    {
        ll k, v; cin >> k >> v;
        ll ans = 0;
        for (ll nv = 1; nv <= n; nv++)
        {
            if (v == nv) continue;
            if (dist[v][nv] >= k)
                ans++;
        }
        cout << ans << "\n";
    }
}