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
ll dp[500];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	dp[0] = 1;
	string s; cin >> s;
	int n = s.size();

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0') continue;
		int n1 = s[i] - '0', n2 = 1e9;
		if (i + 1 < n) 
			n2 = (s[i] - '0') * 10 + (s[i + 1] - '0');
		dp[i + 1] += dp[i];
		if (n2 <= 34) dp[i + 2] += dp[i];
	}

	// dp : 1 index
	cout << dp[n];
}