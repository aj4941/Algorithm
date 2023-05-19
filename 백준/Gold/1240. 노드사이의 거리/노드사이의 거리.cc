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
const int N = 1002;
int n, m, A, B;
vector<pii> g[N];
ll ans = -1;

void dfs(int v, int p, int d)
{
	if (v == B)
	{
		ans = d;
		return;
	}

	for (auto to : g[v])
	{
		int nv = to.first, w = to.second;
		if (nv == p) continue;
		dfs(nv, v, d + w);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> A >> B;
		dfs(A, 0, 0);
		cout << ans << "\n";
	}
}