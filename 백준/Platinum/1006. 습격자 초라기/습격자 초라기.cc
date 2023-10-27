#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
ll dp[10002][3];
ll a[2][10002];
ll n, w;

ll solve(int x, int bit, int en, int ebit)
{
	if (x == en && bit == ebit) return 0;
	if (x > en) return 1e18;
	ll& ret = dp[x][bit];
	if (ret != -1) return ret;
	ret = 1e18;
	if (bit == 0)
	{
		ret = min(solve(x, 1, en, ebit) + 1, solve(x, 2, en, ebit) + 1);
		if (a[0][x] + a[1][x] <= w)
			ret = min(ret, solve(x + 1, 0, en, ebit) + 1);
		if (x + 1 < n)
		{
			if (a[0][x] + a[0][x + 1] <= w && a[1][x] + a[1][x + 1] <= w)
				ret = min(ret, solve(x + 2, 0, en, ebit) + 2);
			if (a[0][x] + a[0][x + 1] <= w)
				ret = min(ret, solve(x + 1, 1, en, ebit) + 2);
			if (a[1][x] + a[1][x + 1] <= w)
				ret = min(ret, solve(x + 1, 2, en, ebit) + 2);
		}
	}
	else if (bit == 1)
	{
		if (a[1][x] + a[1][x + 1] <= w)
			ret = min(ret, solve(x + 1, 2, en, ebit) + 1);
		ret = min(ret, solve(x + 1, 0, en, ebit) + 1);
	}
	else
	{
		if (a[0][x] + a[0][x + 1] <= w)
			ret = min(ret, solve(x + 1, 1, en, ebit) + 1);
		ret = min(ret, solve(x + 1, 0, en, ebit) + 1);
	}
	return ret;
}

void reset()
{
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++)
		dp[i][j] = -1;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> w;
		reset();
		for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++)
			cin >> a[i][j];
		ll ans = 1e18;
		ans = min(ans, solve(0, 0, n, 0));
		reset();
		if (a[0][0] + a[0][n - 1] <= w)
		{
			ans = min(ans, solve(0, 1, n - 1, 2) + 1);
			reset();
		}
		if (a[1][0] + a[1][n - 1] <= w)
		{
			ans = min(ans, solve(0, 2, n - 1, 1) + 1);
			reset();
		}
		if (a[0][0] + a[0][n - 1] <= w && a[1][0] + a[1][n - 1] <= w)
		{
			ans = min(ans, solve(1, 0, n - 1, 0) + 2);
			reset();
		}
		cout << ans << "\n";
	}
}