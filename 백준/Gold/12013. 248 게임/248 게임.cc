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
const int N = 252;
int dp[N][N];
int n, ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < n; i++)
	{
		cin >> dp[i][i];
		ans = max(ans, dp[i][i]);
	}

	for (int sz = 1; sz < n; sz++)
	{
		for (int i = 0; i + sz < n; i++)
		{
			for (int k = i; k < i + sz; k++)
			{
				if (dp[i][k] == -1 || dp[k + 1][i + sz] == -1) continue;
				if (dp[i][k] == dp[k + 1][i + sz])
					dp[i][i + sz] = max(dp[i][i + sz], dp[i][k] + 1);

				ans = max(ans, dp[i][i + sz]);
			}
		}
	}

	cout << ans;
}