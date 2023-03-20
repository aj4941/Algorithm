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
int n, m;
vector<pll> g[N];
ll dist[N], prv[N];
priority_queue<pll> pq;
bool flag = true;

void solve(int a, int b)
{
	dist[1] = 0; pq.push({ 0, 1 });
	while (!pq.empty())
	{
		auto to = pq.top(); pq.pop();
		ll d = -to.first, v = to.second; 
		if (dist[v] != d) continue;
		for (auto to : g[v])
		{
			ll nv = to.first, w = to.second;
			if ((v == a && nv == b) || (v == b && nv == a)) continue;
			if (dist[nv] == -1 || dist[v] + w < dist[nv])
			{
				if (flag) prv[nv] = v;
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
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	solve(0, 0); flag = false;
	ll init = dist[n], v = n, ans = 0;

	while (v != 1)
	{
		memset(dist, -1, sizeof dist);
		solve(v, prv[v]);
		if (dist[n] == -1) ans = 1e9;
		else ans = max(ans, dist[n] - init);
		v = prv[v];
	}

	if (ans == 1e9) ans = -1;
	cout << ans;
}