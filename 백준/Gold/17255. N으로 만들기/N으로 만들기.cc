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
map<string, ll> dp;

ll solve(string a)
{
	if (dp.count(a)) return dp[a];
	dp[a] = 0;
	int len = a.size();
	if (len == 1) return dp[a] = 1;
	string l = a.substr(0, len - 1);
	string r = a.substr(1);

	if (l == r) dp[a] = solve(l);
	else dp[a] = solve(l) + solve(r);

	return dp[a];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;

	cout << solve(s);
}