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
const int N = 2002;
vector<pii> g[N];
int n, m, ans;
int dist[N], prv[N];
bool flag = false;
vector<pii> road;

void solve(int x, int y)
{
	memset(dist, -1, sizeof dist);
	priority_queue<pii> pq; pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty())
	{
		auto to = pq.top(); pq.pop();
		int d = -to.first, v = to.second;
		if (dist[v] != d) continue;
		for (auto to : g[v])
		{
			int nv = to.first, w = to.second;
			if (v == x && nv == y) continue;
			if (v == y && nv == x) continue;
			if (dist[nv] == -1 || dist[v] + w < dist[nv])
			{
				if (!flag) prv[nv] = v;
				dist[nv] = dist[v] + w;
				pq.push({ -dist[nv], nv });
			}
		}
	}

	if (flag)
		ans = max(ans, dist[n]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	solve(-1, -1);

	int v = n;
	while (v != 1)
	{
		road.push_back({ v, prv[v] });
		v = prv[v];
	}

	flag = true;

	for (auto to : road)
		solve(to.first, to.second);

	cout << ans;
}