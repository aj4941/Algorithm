#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1020;
int p[N], n, m;
char c[N];
vector<pair<int, pii>> edge;

int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i < N; i++) p[i] = i;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		if (c[u] == c[v]) continue;
		edge.push_back({ w, { u, v } });
	}

	sort(edge.begin(), edge.end());
	ll ans = 0, sz = 1;

	for (auto to : edge)
	{
		ll w = to.first;
		int u = to.second.first, v = to.second.second;
		u = find(u), v = find(v);
		if (u == v) continue;
		ans += w; p[u] = v; sz++;
	}
	
	if (sz != n) cout << -1;
	else cout << ans;
}