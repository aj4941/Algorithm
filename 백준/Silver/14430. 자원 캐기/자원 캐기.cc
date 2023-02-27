#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, -1 };
int dy[4] = { 0, -1, -1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 400;
int a[N][N], dp[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> a[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		dp[i][j] = a[i][j];
		for (int k = 0; k < 2; k++)
		{
			int ni = i + dx[k], nj = j + dy[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			dp[i][j] = max(dp[i][j], dp[ni][nj] + a[i][j]);
		}
	}

	cout << dp[n - 1][m - 1];
}