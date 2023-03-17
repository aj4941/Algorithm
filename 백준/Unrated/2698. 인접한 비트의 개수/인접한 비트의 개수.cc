#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 130;
ll dp[N][N][2];
int n, k;

ll solve(ll i, ll j, ll c)
{
	ll& ret = dp[i][j][c];
	if (ret != -1) return ret;
	if (j > k) return ret = 0;
	if (i == n - 1)
	{
		if (j == k) return ret = 1;
		else return ret = 0;
	}
	if (c == 0)
		return ret = solve(i + 1, j, 0) + solve(i + 1, j, 1);
	else
		return ret = solve(i + 1, j, 0) + solve(i + 1, j + 1, 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		cout << solve(0, 0, 0) + solve(0, 0, 1) << "\n";
	}
}