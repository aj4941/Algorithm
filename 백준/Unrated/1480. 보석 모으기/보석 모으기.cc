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
const int N = 15;
int val[1 << N];
int dp[N][1 << N];
int n, m, c;

int solve(int idx, int bit)
{
	if (idx == m) return 0;
	int& ret = dp[idx][bit];
	if (ret != -1) return ret;
	for (int tmp = 0; tmp < (1 << n); tmp++)
	{
		if (bit & tmp) continue;
		ret = max(ret, solve(idx + 1, bit | tmp) + val[tmp]);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> c;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int bit = 0; bit < (1 << n); bit++)
	{
		int res = c, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (bit & (1 << i))
			{
				cnt++;
				res -= a[i];
			}
			if (res >= 0)
				val[bit] = cnt;
		}
	}

	cout << solve(0, 0);
}