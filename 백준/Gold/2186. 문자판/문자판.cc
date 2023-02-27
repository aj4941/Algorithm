#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, m, k;
string s[102], t;
int dp[102][102][82];

int solve(int x, int y, int len)
{
	int& ret = dp[x][y][len];
	if (ret != -1) return ret;
	if (len == t.size()) return ret = 1;
	ret = 0;
	for (int c = 0; c < 4; c++) 
	{
		for (int l = 1; l <= k; l++)
		{
			int nx = x + dx[c] * l, ny = y + dy[c] * l;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (s[nx][ny] == t[len]) 
				ret += solve(nx, ny, len + 1);
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> t;

	int ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (s[i][j] == t[0])
			ans += solve(i, j, 1);
	}

	cout << ans;
}