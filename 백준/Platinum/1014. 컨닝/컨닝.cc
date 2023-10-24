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
int dp[15][1200];
string st[15];
int n, m;

bool check(int br, int bx, int r, int x)
{
	bool hasAns = true;
	for (int i = 0; i < m; i++)
	{
		if (st[r][i] == 'x' && x & (1 << i))
			hasAns = false;
		if (i > 0 && x & (1 << i) && x & (1 << (i - 1)))
			hasAns = false;
		if (i < m - 1 && x & (1 << i) && bx & (1 << (i + 1)))
			hasAns = false;
		if (i > 0 && x & (1 << i) && bx & (1 << (i - 1)))
			hasAns = false;
	}
	return hasAns;
}

int solve(int x, int bit)
{
	if (x == n - 1) return 0;
	int& ret = dp[x][bit];
	if (ret != -1) return ret;
	for (int i = 0; i < (1 << m); i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
				cnt++;
		}
		if (check(x, bit, x + 1, i))
			ret = max(ret, solve(x + 1, i) + cnt);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> st[i];
		int ans = -1e9;
		for (int i = 0; i < (1 << m); i++)
		{
			int cnt = 0;
			for (int j = 0; j < m; j++)
			{
				if (i & (1 << j))
					cnt++;
			}
			if (check(0, 0, 0, i))
				ans = max(ans, solve(0, i) + cnt);
		}
		cout << ans << "\n";
	}
}