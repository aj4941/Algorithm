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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 22;
ll dp[N][N][N][N][N];
int n, L;
int a[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> L;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> a[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		dp[i][j][i][j][1] = 1;
		for (int k = 0; k < 8; k++)
		{
			int ni = i + dx[k], nj = j + dy[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
			if (a[i][j] == a[ni][nj])
				dp[i][j][ni][nj][2] = 1;
		}
	}
	for (int l = 3; l <= L; l++)
	{
		for (int i1 = 0; i1 < n; i1++) for (int j1 = 0; j1 < n; j1++)
		{
			for (int i2 = 0; i2 < n; i2++) for (int j2 = 0; j2 < n; j2++)
			{
				if (a[i1][j1] != a[i2][j2]) continue;

				for (int k1 = 0; k1 < 8; k1++) for (int k2 = 0; k2 < 8; k2++)
				{
					int ni1 = i1 + dx[k1], nj1 = j1 + dy[k1];
					int ni2 = i2 + dx[k2], nj2 = j2 + dy[k2];
					if (ni1 < 0 || nj1 < 0 || ni1 >= n || nj1 >= n) continue;
					if (ni2 < 0 || nj2 < 0 || ni2 >= n || nj2 >= n) continue;
					if (a[ni1][nj1] != a[ni2][nj2]) continue;
					dp[i1][j1][i2][j2][l] += dp[ni1][nj1][ni2][nj2][l - 2];
				}

			}
		}
	}

	ll ans = 0;

	for (int i1 = 0; i1 < n; i1++) for (int j1 = 0; j1 < n; j1++)
	{
		for (int i2 = 0; i2 < n; i2++) for (int j2 = 0; j2 < n; j2++)
			ans += dp[i1][j1][i2][j2][L];
	}

	cout << ans;
}