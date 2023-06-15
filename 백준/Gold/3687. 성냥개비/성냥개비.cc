#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long long ll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll c[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
ll dp[102];

ll solve(ll x)
{
	ll& ret = dp[x];
	if (ret != -1) return ret;
	if (x == 0) return ret = 0;
	ret = 1e15;
	for (ll i = 0; i < 10; i++)
	{
		if (x - c[i] >= 0 && x - c[i] != 1)
			ret = min(ret, solve(x - c[i]) * 10 + i);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	dp[6] = 6;
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << solve(n) << " ";
		if (n % 2 == 0)
		{
			for (int i = 0; i < n / 2; i++)
				cout << 1;
		}
		else
		{
			cout << 7; n -= 3;
			for (int i = 0; i < n / 2; i++)
				cout << 1;
		}
		cout << "\n";
	}
}