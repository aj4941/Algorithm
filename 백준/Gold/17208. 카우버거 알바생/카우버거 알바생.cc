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
const int N = 302;
int dp[N][N][N];
int n, m, k;
int a[N], b[N];

int solve(int idx, int M, int K)
{
	int& ret = dp[idx][M][K];
	if (ret != -1) return ret;
	if (idx == n) return ret = 0;
	ret = solve(idx + 1, M, K);
	if (M - a[idx] >= 0 && K - b[idx] >= 0)
		ret = max(ret, solve(idx + 1, M - a[idx], K - b[idx]) + 1);

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	cout << solve(0, m, k);
}