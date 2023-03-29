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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 60000;
int n, m;
vector<int> g[N];
int cache[N];
bool hasAns = true;

void dfs(int v, int c)
{
	cache[v] = c;
	for (int nv : g[v])
	{
		if (cache[nv])
		{
			if (cache[v] == cache[nv])
				hasAns = false;
			continue;
		}
		dfs(nv, 1 + 2 - c);
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
		g[u].push_back(v); g[v].push_back(u);
	}

	dfs(1, 1);

	if (!hasAns)
	{
		cout << 0;
		return 0;
	}

	ll s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cache[i] == 1) s1++;
		else s2++;
	}

	cout << s1 * s2 * 2;
}