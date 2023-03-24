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
const int N = 20002;
const ll V = 10005;
vector<pll> g[N], st_g[N], mac_g[N];
ll n, m, x, y;
bool st_cache[N], mac_cache[N];
ll st_dist[N], mac_dist[N];

void solve(ll dist[], vector<pll> g[])
{
	priority_queue<pll> pq; pq.push({ 0, V });
	dist[V] = 0;
	while (!pq.empty())
	{
		auto to = pq.top(); pq.pop();
		ll d = -to.first, v = to.second;
		if (dist[v] != d) continue;
		for (auto to : g[v])
		{
			ll nv = to.first, w = to.second;
			if (dist[nv] == -1 || dist[v] + w < dist[nv])
			{
				dist[nv] = dist[v] + w;
				pq.push({ -dist[nv], nv });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		st_g[u].push_back({ v, w }); st_g[v].push_back({ u, w });
		mac_g[u].push_back({ v, w }); mac_g[v].push_back({ u, w });
	}

	ll len, x; cin >> len >> x;
	for (ll i = 0; i < len; i++)
	{
		ll x; cin >> x;
		mac_cache[x] = true;
		mac_g[V].push_back({ x, 0 });
	}

	ll y; cin >> len >> y;
	for (ll i = 0; i < len; i++)
	{
		ll x; cin >> x;
		st_cache[x] = true;
		st_g[V].push_back({ x, 0 });
	}

	memset(mac_dist, -1, sizeof mac_dist);
	memset(st_dist, -1, sizeof st_dist);

	solve(mac_dist, mac_g); solve(st_dist, st_g);

	ll ans = 1e18;

	for (ll i = 1; i <= n; i++)
	{
		if (!st_cache[i] && !mac_cache[i])
		{
			if (st_dist[i] == -1 || mac_dist[i] == -1) continue;
			if (st_dist[i] <= y && mac_dist[i] <= x)
				ans = min(ans, st_dist[i] + mac_dist[i]);
		}
	}

	if (ans == 1e18) ans = -1;
	cout << ans;
}