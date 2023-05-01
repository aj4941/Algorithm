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
int n, k;
int dp[1002][10002];
vector<pii> v;

int solve(int idx, int val)
{
	int& ret = dp[idx][val];
	if (ret != -1) return ret;
	if (idx == k) return 0;
	ret = solve(idx + 1, val);
	if (val - v[idx].second >= 0)
		ret = max(ret, solve(idx + 1, val - v[idx].second) + v[idx].first);
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	memset(dp, -1, sizeof dp);

	for (int i = 0; i < k; i++)
	{
		int l, t; cin >> l >> t;
		v.push_back({ l, t });
	}

	cout << solve(0, n);
}