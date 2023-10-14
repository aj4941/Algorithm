#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll N = 120;
const ll inf = 1000000;
ll n;
ll dp[N][N][N][2];
ll ans = 0;

ll solve(ll idx, ll l, ll r, ll c)
{
	if (idx == n) return 1;
	ll& ret = dp[idx][l][r][c];
	if (ret != -1) return ret;
	ret = 0;
	if (c == 0)
	{
		for (ll i = 1; i <= l; i++) // 왼쪽에서 선택한 번호
		{
			ret += solve(idx + 1, i - 1, r + (l - i), 1) % inf;
			ret %= inf;
		}
	}
	else
	{
		for (ll i = 1; i <= r; i++)
		{
			ret += solve(idx + 1, l + (i - 1), r - i, 0) % inf;
			ret %= inf;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	for (ll i = 0; i < n; i++)
	{
		ans = (ans + solve(1, i, (n - 1 - i), 0)) % inf; ans %= inf;
		ans = (ans + solve(1, i, (n - 1 - i), 1)) % inf; ans %= inf;
	}

	cout << ans;
}