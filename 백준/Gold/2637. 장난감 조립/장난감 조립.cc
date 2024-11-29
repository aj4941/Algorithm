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
const ll N = 120;
vector<pll> g[N];
ll dp[N], indegree[N], n, m;

ll solve(ll v)
{
	ll& ret = dp[v];
	if (ret != -1) return ret;
	if (g[v].size() == 0)
		return ret = 1;

	ret = 0;

	for (auto &to : g[v])
	{
		ll nv = to.first, w = to.second;
		ret += solve(nv) * w;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		ll x, y, k; cin >> x >> y >> k;
		g[y].push_back({ x, k }); indegree[x]++;
	}

	for (ll i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			cout << i << ' ' << solve(i) << "\n";
	}
}