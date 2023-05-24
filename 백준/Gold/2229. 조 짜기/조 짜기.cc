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
const int N = 1002;
int n;
ll dp[N], a[N];

ll solve(int x)
{
	ll& ret = dp[x];
	if (ret != -1) return ret;
	if (x == n) return ret = 0;
	ret = solve(x + 1);
	ll mn = a[x], mx = a[x];
	for (int i = x + 1; i < n; i++)
	{
		mn = min(mn, a[i]), mx = max(mx, a[i]);
		ret = max(ret, solve(i + 1) + mx - mn);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << solve(0);
}
