#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
int p[50002];
vector<pair<ll, pll>> edge;
vector<pair<ll, pll>> sec;
vector<pll> graph[50002];
pll par[50002];
ll lv[50002];

ll find(ll x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

void dfs(int v, int p, int l, ll w)
{
	lv[v] = l;
	par[v] = { p, w };
	for (auto to : graph[v])
	{
		ll nv = to.first, nw = to.second;
		if (nv == p) continue;
		dfs(nv, v, l + 1, nw);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll v, e; cin >> v >> e;
	for (ll i = 0; i < e; i++)
	{
		ll x, y, w; cin >> x >> y >> w;
		edge.push_back({ w, { x, y } });
	}
	for (ll i = 1; i <= v; i++) p[i] = i;
	sort(edge.begin(), edge.end());
	ll ans = 0, cnt = 0;
	for (ll i = 0; i < e; i++)
	{
		ll w = edge[i].first;
		ll x = edge[i].second.first, y = edge[i].second.second;
		if (find(x) != find(y))
		{
			cnt++;
			ans += w;
			graph[x].push_back({ y, w });
			graph[y].push_back({ x, w });
			x = find(x); y = find(y);
			p[x] = y;
		}
		else
			sec.push_back({ w, { x, y } });
	}
	if (cnt != v - 1)
	{
		cout << -1;
		return 0;
	}
	dfs(1, 0, 0, -1e15);
	ll m = sec.size();
	ll res = ans;
	ans = 1e15;
	while (--m >= 0)
	{
		ll u = sec[m].second.first, v = sec[m].second.second;
		ll w = sec[m].first;
		ll lv_u = lv[u], lv_v = lv[v];
		ll tmp = -1e15;
		while (lv_u > lv_v)
		{
			if (w > par[u].second)
				tmp = max(tmp, par[u].second);
			u = par[u].first;
			lv_u--;
		}
		while (lv_v > lv_u)
		{
			if (w > par[v].second)
				tmp = max(tmp, par[v].second);
			v = par[v].first;
			lv_v--;
		}
		while (u != v)
		{
			if (w > par[u].second)
				tmp = max(tmp, par[u].second);
			u = par[u].first;
			if (w > par[v].second)
				tmp = max(tmp, par[v].second);
			v = par[v].first;
		}
		if (tmp != -1e15)
			ans = min(ans, res + w - tmp);
	}
	if (ans == 1e15) ans = -1;
	cout << ans;
}