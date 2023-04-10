#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll N = 1002;
const ll inf = 1000000003;
ll dp[N][2][N];
ll n, k;

ll solve(ll x, ll y, ll k, ll ex, ll ey, ll ek)
{
	ll& ret = dp[x][y][k];
	if (ret != -1) return ret;
	if (x == ex && y == ey && k == ek) return ret = 1;
	if (x == ex) return ret = 0;
	ret = 0;
	ret += solve(x + 1, 0, k, ex, ey, ek); ret %= inf;
	if (y == 0 && k >= 1)
	{
		ret += solve(x + 1, 1, k - 1, ex, ey, ek);
		ret %= inf;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	ll ans = 0;
	ans += solve(0, 1, k - 1, n - 1, 0, 0); ans %= inf;
	memset(dp, -1, sizeof dp);
	ans += solve(0, 0, k, n - 1, 1, 0); ans %= inf;
	memset(dp, -1, sizeof dp);
	ans += solve(0, 0, k, n - 1, 0, 0); ans %= inf;
	cout << ans;
}