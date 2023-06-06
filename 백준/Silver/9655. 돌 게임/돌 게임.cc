#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll dp[1002];

ll solve(ll x)
{
	ll& ret = dp[x];
	if (ret != -1) return ret;
	if (x - 1 >= 0)
	{
		if (solve(x - 1) == 0) 
			return ret = 1;
	}
	if (x - 3 >= 0)
	{
		if (solve(x - 3) == 0) 
			return ret = 1;
	}
	return ret = 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	if (solve(n)) cout << "SK";
	else cout << "CY";
}
