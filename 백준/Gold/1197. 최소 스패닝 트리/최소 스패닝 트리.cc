#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1e18
const int N = 10002;
ll p[N];

ll find(ll v)
{
    if (p[v] == v) return v;
    else return p[v] = find(p[v]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll v, e; cin >> v >> e;
    vector<pair<ll, pll>> graph(e);
    for (ll i = 1; i <= v; i++) p[i] = i;
    for (ll i = 0; i < e; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        graph[i] = { w, { u, v } };
    }
    sort(graph.begin(), graph.end());
    ll ans = 0;
    for (ll i = 0; i < e; i++)
    {
        ll w = graph[i].first;
        ll x = graph[i].second.first;
        ll y = graph[i].second.second;
        x = find(x); y = find(y);
        if (x != y)
        {
            p[x] = y;
            ans += w;
        }
    }
    cout << ans;
}