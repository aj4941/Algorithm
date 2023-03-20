#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1002;
int n, m;
ll dp[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<ll> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = 1e15;

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
			dp[i][j] = 1e15;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(a[i] - b[j]));
			else if (i > j)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(a[i] - b[j]));
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(a[i] - b[j]));
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m];
}