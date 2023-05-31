#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ull inf = (1ll << 64ll) - 1;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n), b(n), c(n), d(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<ll> v1, v2;

	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++)
		v1.push_back(a[i] + b[j]);

	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++)
		v2.push_back(c[i] + d[j]);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll ans = 0;

	for (auto to : v1)
	{
		ll cnt = upper_bound(v2.begin(), v2.end(), -to)
			- lower_bound(v2.begin(), v2.end(), -to);

		ans += cnt;
	}

	cout << ans;
}