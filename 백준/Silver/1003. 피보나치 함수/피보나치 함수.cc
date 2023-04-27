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
int n;
pll dp[100];

pii solve(int x)
{
	pll& ret = dp[x];
	if (ret.first != -1) return ret;
	if (x == 0) return pll(1, 0);
	if (x == 1) return pll(0, 1);
	pll r1 = solve(x - 1), r2 = solve(x - 2);
	ret.first = r1.first + r2.first;
	ret.second = r1.second + r2.second;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i <= 40; i++) dp[i] = pll(-1, -1);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		pll res = solve(n);
		cout << res.first << ' ' << res.second << "\n";
	}
}
