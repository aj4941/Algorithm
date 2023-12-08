#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int gcd(int a, int b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 10987654321
vector<vector<pll>> graph;
ll dist[22][10002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		ll w; cin >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}
	for (int i = 0; i <= 21; i++) for (int j = 0; j <= 10001; j++)
		dist[i][j] = 1e18;
	dist[0][1] = 0;
	priority_queue<pair<ll, pll>> pq;
	pq.push({ 0, { 0, 1 } });
	while (!pq.empty())
	{
		ll w = -pq.top().first;
		int x = pq.top().second.first;
		int v = pq.top().second.second; pq.pop();
		if (dist[x][v] != w) continue;
		for (pll to : graph[v])
		{
			int nv = to.first;
			ll nw = to.second;
			if (x + 1 <= k)
			{
				if (dist[x + 1][nv] > dist[x][v])
				{
					dist[x + 1][nv] = dist[x][v];
					pq.push({ -dist[x + 1][nv], { x + 1, nv } });
				}
			}
			if (dist[x][nv] > dist[x][v] + nw)
			{
				dist[x][nv] = dist[x][v] + nw;
				pq.push({ -dist[x][nv], { x, nv } });
			}
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= k; i++) ans = min(ans, dist[i][n]);
	cout << ans;
}