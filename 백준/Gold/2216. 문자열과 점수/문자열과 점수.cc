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
const ll N = 4002;
ll a, b, c;
string s, t;
ll dp[N][N];

ll solve(ll x, ll y)
{
	if (x == s.size() && y == t.size()) return 0;
	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = -1e15;
	if (x < s.size())
		ret = max(ret, solve(x + 1, y) + b);
	if (y < t.size())
		ret = max(ret, solve(x, y + 1) + b);
	if (x < s.size() && y < t.size())
	{
		if (s[x] == t[y])
			ret = max(ret, solve(x + 1, y + 1) + a);
		else
			ret = max(ret, solve(x + 1, y + 1) + c);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> a >> b >> c;
	cin >> s >> t;

	cout << solve(0, 0);
}