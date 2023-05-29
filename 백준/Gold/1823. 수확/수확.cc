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
const int N = 2005;
ll dp[N][N], a[N];
ll n;

ll solve(ll l, ll r)
{
	if (l > r) return 0;
	ll& ret = dp[l][r];
	if (ret != -1) return ret;
	ll k = (l - 1) + (n - r) + 1;
	ret = max(solve(l + 1, r) + k * a[l], solve(l, r - 1) + k * a[r]);

	return ret;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];

	cout << solve(1, n);
}