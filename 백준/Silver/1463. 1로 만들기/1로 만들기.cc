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
const int N = 1000002;
ll dp[N];
int n;

ll solve(int x)
{
	ll& ret = dp[x];
	if (ret != -1) return ret;
	if (x == 1) return ret = 0;
	ret = 1e9;
	if (x % 3 == 0) ret = min(ret, solve(x / 3) + 1);
	if (x % 2 == 0) ret = min(ret, solve(x / 2) + 1);
	return ret = min(ret, solve(x - 1) + 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	cout << solve(n);
}