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
const int N = 10020;
vector<pll> v;
ll dp[N], n;

ll solve(int i)
{
	ll& ret = dp[i];
	if (ret != -1) return ret;
	if (i == n) return ret = 0;
	ret = 1e18;
	ll h = v[i].second;
	for (int ni = i; ni < n; ni++)
	{
		h = max(h, v[ni].second);
		ll len = max(v[ni].first - v[i].first, h);
		ret = min(ret, solve(ni + 1) + len);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		v.push_back({ x, abs(y) * 2 });
	}

	sort(v.begin(), v.end());

	cout << solve(0);
}