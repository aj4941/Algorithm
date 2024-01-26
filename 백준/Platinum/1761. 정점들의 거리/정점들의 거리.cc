#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007 
vector<pii> graph[40002];
int lv[40002];
pii sp[21][40002];

void dfs(int v, int p, int l)
{
	sp[0][v].first = p;
	lv[v] = l;
	for (pii to : graph[v])
	{
		int nv = to.first;
		int len = to.second;
		if(nv == p) sp[0][v].second = len;
		if (nv == p) continue;
		dfs(nv, v, l + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			sp[i][j].first = sp[i - 1][sp[i - 1][j].first].first;
			sp[i][j].second = sp[i - 1][sp[i - 1][j].first].second + sp[i - 1][j].second;
		}
	}
	int m; cin >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		if (lv[u] > lv[v]) swap(u, v);
		int d = lv[v] - lv[u];
		ll ans = 0;
		for (int i = 0; i <= 20; i++)
		{
			if (d & (1 << i))
			{
				ans += sp[i][v].second;
				v = sp[i][v].first;
			}
		}
		if (u == v)
		{
			cout << ans << "\n";
			continue;
		}
		for (int i = 20; i >= 0; i--)
		{
			if (sp[i][u].first != sp[i][v].first)
			{
				ans += sp[i][u].second;
				ans += sp[i][v].second;
				u = sp[i][u].first;
				v = sp[i][v].first;
			}
		}
		ans += sp[0][u].second; ans += sp[0][v].second;
		cout << ans << "\n";
	}
}