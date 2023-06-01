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
ll dp[32][32];

ll solve(ll x, ll y)
{
	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	if (x == 0 && y == 0) return ret = 1;
	ret = 0;
	if (x > 0)
		ret += solve(x - 1, y + 1);
	if (y > 0)
		ret += solve(x, y - 1);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (true)
	{
		memset(dp, -1, sizeof dp);
		ll n; cin >> n;
		if (n == 0) break;
		cout << solve(n, 0) << "\n";
	}
}