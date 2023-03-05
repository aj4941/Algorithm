#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dp[62][62][62];
int a[3];

int solve(int x, int y, int z)
{
	int& ret = dp[x][y][z];
	if (ret != -1) return ret;
	if (x == 0 && y == 0 && z == 0) return ret = 0;
	ret = 1e9;
	vector<int> p = { 1, 3, 9 };
	do {
		int cx = max(0, x - p[0]), cy = max(0, y - p[1]), cz = max(0, z - p[2]);
		ret = min(ret, solve(cx, cy, cz) + 1);
	} while (next_permutation(p.begin(), p.end()));

	return ret; 
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve(a[0], a[1], a[2]);
}