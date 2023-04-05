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
const ll N = 600;
ll n, k;
ll dp[N][N];

ll solve(ll x, ll y)
{
	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	if (x == 0) return ret = 0;
	if (y == 0) return ret = 1e9;
	ret = solve(x - 1, y) + 1;
	for (ll nx = 1; nx <= x; nx++)
	{
		ll r1 = solve(nx - 1, y - 1) + 1; // 깨지는 경우
		ll r2 = solve(x - nx, y) + 1; // 깨지지 않는 경우
		ll res = max(r1, r2);
		ret = min(ret, res);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	cout << solve(n, k);
}