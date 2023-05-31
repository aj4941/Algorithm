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
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 6002;
int n, m;
ll dist[N];
vector<pii> g[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) dist[i] = 1e15;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	int s, t; cin >> s >> t;

	priority_queue<pii> pq; pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty())
	{
		auto to = pq.top();
		int d = to.first, v = to.second; pq.pop();

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

	cout << dist[t];
}