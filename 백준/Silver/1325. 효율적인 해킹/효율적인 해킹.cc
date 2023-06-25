#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int mx = 0, res = 0;
int cache[10002];
vector<vector<int>> g;

void dfs(int v)
{
	res++; 
	cache[v] = 1;
	for (int nv : g[v])
	{
		if (!cache[nv])
			dfs(nv);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		g[v].push_back(u);
	}
	vector<int> tmp;
	for (int i = 1; i <= n; i++)
	{
		memset(cache, 0, sizeof cache);
		res = 0;
		dfs(i);
		if (mx < res)
		{
			tmp.clear();
			tmp.push_back(i);
			mx = res;
		}
		else if (mx == res)
			tmp.push_back(i);
	}
	for (int to : tmp) cout << to << ' ';
}