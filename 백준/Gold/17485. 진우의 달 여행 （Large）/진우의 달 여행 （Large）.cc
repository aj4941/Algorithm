#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 2000;
ll a[N][N], dp[N][N][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		if (i == 1)
		{
			for (ll k = 0; k < 3; k++)
				dp[i][j][k] = a[i][j];
		}
		else 
		{
			for (ll k = 0; k < 3; k++)
				dp[i][j][k] = 1e9;
		}
	}

	for (ll i = 2; i <= n; i++) for (ll j = 1; j <= m; j++)
	{
		for (ll k = 0; k < 3; k++)
		{
			ll bi = i + dx[k], bj = j + dy[k];
			if (bj < 1 || bj > m) continue;
			ll res = 1e9;
			for (ll nk = 0; nk < 3; nk++)
			{
				if (nk == k) continue;
				res = min(res, dp[bi][bj][nk] + a[i][j]); 
			}
			dp[i][j][k] = res;
		}
	}

	ll ans = 1e9;
	for (ll k = 0; k < 3; k++)
	{
		for (ll j = 1; j <= m; j++)
			ans = min(ans, dp[n][j][k]);
	}

	cout << ans;
}