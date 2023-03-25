#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200002;
int n, m;
vector<int> g[N];
int cache[N], cycle[N];

void dfs(int v)
{
	cache[v] = 1;
	for (int nv : g[v])
	{
		if (cache[nv] == 2) continue;
		if (cache[nv] == 1) cycle[v] = 1;
		else dfs(nv);
	}
	cache[v] = 2;
}

void calc(int v)
{
	cache[v] = 1;
	for (int nv : g[v])
	{
		if (cycle[nv]) cycle[v] = 1;
		else if (!cache[nv])
		{
			calc(nv);
			if (cycle[nv]) cycle[v] = 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (cache[i] == 0)
			dfs(i);
	}

	memset(cache, 0, sizeof cache);
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (cache[i] == 0) calc(i);
		if (cycle[i] == 0) ans++;
	}

	cout << ans;
}