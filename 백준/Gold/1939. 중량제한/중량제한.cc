#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100002;
vector<pii> g[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	int s, e; cin >> s >> e;
	int l = 0, r = 1e9 + 1;

	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		vector<bool> cache(n + 1, false); cache[s] = true;
		queue<int> q; q.push(s);
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (auto to : g[v])
			{
				int nv = to.first, w = to.second;
				if (cache[nv]) continue;
				if (mid <= w)
				{
					q.push(nv);
					cache[nv] = true;
				}
			}
		}

		if (cache[e]) l = mid;
		else r = mid;
	}

	cout << l;
}