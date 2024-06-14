#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 1002;
ll p[N];

ll find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        u = find(u), v = find(v); p[u] = v;
    }

    vector<pair<ll, pll>> edge;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        ll x; cin >> x;
        if (i == j || i == 1 || j == 1) continue;
        edge.push_back({ x, { i, j }});
    }

    sort(edge.begin(), edge.end());

    ll ans = 0;
    vector<pll> res;

    for (auto to : edge)
    {
        ll w = to.first, u = to.second.first, v = to.second.second;
        ll pu = find(u), pv = find(v);
        if (pu == pv) continue;
        ans += w; res.push_back({ u, v }); p[pu] = pv;
    }

    cout << ans << ' ' << res.size() << "\n";

    for (auto to : res)
        cout << to.first << ' ' << to.second << "\n";
}