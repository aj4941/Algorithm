#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 101112987654321

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc; cin >> tc;
    while (tc--)
    {
        ll n, m, w;
        cin >> n >> m >> w;
        vector<vector<pll>> graph(n + 1);
        vector<ll> dist(n + 1, INF);
        for (ll i = 1; i <= n; i++) graph[0].push_back({ i, 0 });
        dist[0] = 0;
        for (ll i = 0; i < m; i++)
        {
            ll u, v, t; cin >> u >> v >> t;
            graph[u].push_back({ v, t });
            graph[v].push_back({ u, t });
        }
        for (ll i = 0; i < w; i++)
        {
            ll u, v, t; cin >> u >> v >> t;
            graph[u].push_back({ v, -t });

        }
        bool flag = false;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 0; j <= n; j++)
            {
                for (pll to : graph[j])
                {
                    ll next = to.first;
                    ll ndist = to.second;
                    if (dist[j] != INF && dist[next] > dist[j] + ndist)
                    {
                        dist[next] = dist[j] + ndist;
                        if (i == n) flag = true;
                    }
                }
            }
        }
        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}