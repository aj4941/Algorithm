#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const ll N = 2002;
ll cache[N][N];
ll n, m, k;
vector<pll> g[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    vector<ll> p(m + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
        p[i] = w;
    }
    sort(p.begin(), p.end());
    ll l = -1, r = p.size();

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        for (ll i = 0; i <= n; i++) for (ll j = 0; j <= k; j++)
            cache[i][j] = 0;

        queue<pll> q; q.push({ 1, 0 });
        cache[1][0] = 1;

        while (!q.empty())
        {
            ll v = q.front().first, c = q.front().second; q.pop();
            for (auto& to : g[v])
            {
                ll nv = to.first, w = to.second;
                if (w <= p[mid])
                {
                    if (cache[nv][c] == 1) continue;
                    q.push({ nv, c }); cache[nv][c] = 1;
                }
                else if (c + 1 <= k)
                {
                    if (cache[nv][c + 1] == 1) continue;
                    q.push({ nv, c + 1 }); cache[nv][c + 1] = 1;
                }
            }
        }

        bool hasAns = false;
        for (ll i = 0; i <= k; i++)
        {
            if (cache[n][i] == 1)
                hasAns = true;
        }

        if (hasAns) r = mid;
        else l = mid;
    }

    if (r == p.size())
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << p[r] << "\n";
}