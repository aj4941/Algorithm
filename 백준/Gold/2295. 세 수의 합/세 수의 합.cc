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
map<ll, ll> sum;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		sum[a[i] + a[j]] = 1;

	ll ans = 0;

	for (int k = 0; k < n; k++) for (int z = 0; z < n; z++)
	{
		ll res = a[k] - a[z];
		if (res < 0) continue;
		if (sum.count(res))
			ans = max(ans, res + a[z]);
	}

	cout << ans;
}