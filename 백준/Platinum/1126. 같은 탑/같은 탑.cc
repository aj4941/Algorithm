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
#define MAX 500002
ll dp[52][MAX];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i < MAX; i++) dp[0][i] = -INF;
	ll n; cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= MAX; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j + a[i] <= MAX && dp[i - 1][j + a[i]] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]]);
			if (j - a[i] >= 0 && dp[i - 1][j - a[i]] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
			else
				dp[i][j] = max(dp[i][j], dp[i - 1][a[i] - j] + j);
		}
	}
	if (dp[n][0] == 0) dp[n][0] = -1;
	cout << dp[n][0];
}