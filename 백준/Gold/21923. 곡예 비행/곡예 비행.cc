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
const int N = 2002;
int n, m;
ll a[N][N], dp[N][N][3];

ll solve(int x, int y, int c)
{
	ll& ret = dp[x][y][c];
	if (ret != -1) return ret;
	ret = a[x][y];
	if (x == n - 1 && y == m - 1 && c == 1)
		return ret;

	ll res = -1e15;

	if (c == 0)
	{
		res = max(res, solve(x, y, 1));
		if (x - 1 >= 0)
			res = max(res, solve(x - 1, y, c));
		if (y + 1 < m)
			res = max(res, solve(x, y + 1, c));
	}
	else
	{
		if (x + 1 < n)
			res = max(res, solve(x + 1, y, c));
		if (y + 1 < m)
			res = max(res, solve(x, y + 1, c));
	}

	ret += res;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> a[i][j];

	cout << solve(n - 1, 0, 0);
}