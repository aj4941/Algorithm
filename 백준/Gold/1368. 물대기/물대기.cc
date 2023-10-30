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
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
// https://conkjh032.tistory.com/386
const ll N = 302;
ll n;
vector<pair<ll, pll>> edge;
ll p[N];

ll find(ll x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++) p[i] = i;

    for (ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        edge.push_back({ x, { 0, i } });
    }

    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
    {
        ll x; cin >> x;
        edge.push_back({ x, { i, j } });
    }

    sort(edge.begin(), edge.end());

    ll ans = 0;

    for (ll i = 0; i < edge.size(); i++)
    {
        ll u = edge[i].second.first, v = edge[i].second.second;
        u = find(u); v = find(v);
        if (u != v)
        {
            p[u] = v;
            ans += edge[i].first;
        }
    }

    cout << ans;
}