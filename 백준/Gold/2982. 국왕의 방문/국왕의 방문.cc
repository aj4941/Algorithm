#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1002;
ll n, m;
ll a, b, k, g;
vector<ll> r;
vector<pll> G[N];
ll dist[N];
ll road[N][N], mn[N][N], mx[N][N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> a >> b >> k >> g;
    for (int i = 0; i < g; i++)
    {
        ll x; cin >> x;
        r.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
        road[u][v] = road[v][u] = w;
    }

    ll w = 0;

    for (int i = 1; i < r.size(); i++)
    {
        ll u = r[i - 1], v = r[i];
        mn[u][v] = mn[v][u] = w;
        mx[u][v] = mx[v][u] = w + road[u][v] - 1;
        w += road[u][v];
    }

    for (int i = 1; i < N; i++) dist[i] = 1e15;
    dist[a] = k;
    priority_queue<pll> pq; pq.push({ -dist[a], a });

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        ll w = -to.first, v = to.second;
        if (dist[v] != w) continue;
        for (auto to : G[v])
        {
            ll nv = to.first, c = to.second;
            ll nd = dist[v] + c;
            if (mn[v][nv] <= dist[v] && dist[v] <= mx[v][nv])
                nd = mx[v][nv] + 1 + c;

            if (nd < dist[nv])
            {
                dist[nv] = nd;
                pq.push({ -dist[nv], nv });
            }
        }
    }

    cout << dist[b] - k;
}