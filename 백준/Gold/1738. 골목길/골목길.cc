#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll N = 120;
const ll inf = 1e15;
ll n, m;
vector<pll> g[N];
ll prv[N], dist[N];
vector<ll> ans, rg[N];
bool cache[N];

void solve(ll v)
{
	ans.push_back(v);
	if (v == 1) return;
	solve(prv[v]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 2; i <= n; i++) dist[i] = inf;
	for (ll i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, -w });
		rg[v].push_back(u);
	}

	cache[n] = true;
	queue<ll> q; q.push(n);
	while (!q.empty())
	{
		ll v = q.front(); q.pop();
		for (ll nv : rg[v])
		{
			if (cache[nv]) continue;
			cache[nv] = true;
			q.push(nv);
		}
	}
	bool cycle = false;
	for (ll c = 1; c <= n; c++) // 시행 횟수
	{
		for (ll v = 1; v <= n; v++)
		{
			if (dist[v] == inf) continue;
			for (auto to : g[v])
			{
				ll nv = to.first, w = to.second;
				if (dist[nv] > dist[v] + w)
				{
					if (c == n && cache[v]) cycle = true;
					dist[nv] = dist[v] + w;
					prv[nv] = v;
				}
			}
		}
	}

	if (cycle || dist[n] == inf)
	{
		cout << -1;
		return 0;
	}

	solve(n); reverse(ans.begin(), ans.end());
	for (auto to : ans)
		cout << to << ' ';
}