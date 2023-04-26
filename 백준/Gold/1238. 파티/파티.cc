#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1002;

void solve(int x, vector<pii> g[], int dist[])
{
	priority_queue<pii> pq;
	pq.push({ dist[x], x });
	while (!pq.empty())
	{
		int v = pq.top().second;
		int d = -pq.top().first; pq.pop();
		if (dist[v] != d) continue;
		for (auto to : g[v])
		{
			int nv = to.first, w = to.second;
			if (dist[nv] > dist[v] + w)
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
	vector<pii> g[N], rg[N];
	int g_dist[N], rg_dist[N];
	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i <= n; i++)
		g_dist[i] = rg_dist[i] = 1e9;

	g_dist[x] = rg_dist[x] = 0;

	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		rg[v].push_back({ u, w });
	}
	solve(x, g, g_dist); solve(x, rg, rg_dist);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, g_dist[i] + rg_dist[i]);

	cout << ans;
}