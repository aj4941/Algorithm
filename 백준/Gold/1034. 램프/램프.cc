#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
map<ll, ll> mp;
string s[100];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int k; cin >> k;
	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		ll bit = 0, zero = 0;
		for (int j = 0; j < m; j++)
		{
			zero += (s[i][j] == '0') ? 1 : 0;
			bit += (1ll << j) * (s[i][j] - '0');
		}
		mp[bit]++;
		if (zero <= k && zero % 2 == k % 2)
			ans = max(ans, mp[bit]);
	}

	cout << ans;
}