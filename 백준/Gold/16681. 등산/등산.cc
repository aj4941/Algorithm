#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const ll N = 100002;
ll n, m, d, e;
ll h[N];
vector<pll> g[N];

void solve(int v, vector<ll> &dist)
{
    priority_queue<pll> pq; pq.push({ 0, v });
    dist[v] = 0;
    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        ll d = -to.first, cv = to.second;
        if (dist[cv] != d) continue;
        for (auto &too : g[cv])
        {
            ll nv = too.first, w = too.second;
            if (h[nv] <= h[cv]) continue;
            if (dist[nv] == -1 || dist[cv] + w < dist[nv])
            {
                dist[nv] = dist[cv] + w;
                pq.push({ -dist[nv], nv });
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d >> e;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    vector<ll> adist(n + 1, -1), bdist(n + 1, -1);
    solve(1, adist); // adist : 1 -> x
    solve(n, bdist); // bdist : n -> x

    ll ans = -1e18;

    for (int x = 2; x <= n; x++)
    {
        if (adist[x] == -1 || bdist[x] == -1) continue;
        ll dist = (adist[x] + bdist[x]) * d;
        ll hE = h[x] * e;
        ans = max(ans, hE - dist);
    }

    if (ans == -1e18)
        cout << "Impossible" << "\n";
    else
        cout << ans << "\n";
}