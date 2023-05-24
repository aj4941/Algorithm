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
const int N = 5002;
const ll inf = 1000000007;
int p[N];
int n, m;
ll dp[N][N];

int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	dp[0][0] = 1;

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + (j * dp[i - 1][j]) % inf;
			dp[i][j] %= inf;
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= i; j++)
		{
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= inf;
		}
	}

	int sz = n;

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u = find(u), v = find(v);

		if (u != v) sz--;
		p[u] = v;

		cout << dp[sz][sz] << "\n";
	}
}