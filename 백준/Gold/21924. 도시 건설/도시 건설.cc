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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100002;
int p[N];
vector<pair<int, pii>> edge;

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll total = 0;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({ w, { u, v }});
        total += w;
    }

    sort(edge.begin(), edge.end());
    ll ans = 0;

    for (auto to : edge)
    {
        int w = to.first;
        int u = to.second.first, v = to.second.second;
        u = find(u), v = find(v);
        if (u == v) continue;
        p[u] = v; ans += w;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            cnt++;
    }

    if (cnt == 1) cout << total - ans;
    else cout << -1;
}