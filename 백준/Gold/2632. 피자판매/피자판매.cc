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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll S, n, m; cin >> S >> n >> m;
	ll asum = 0, bsum = 0;
	vector<ll> a, b, v1, v2;

	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		a.push_back(x); asum += x;
	}


	for (ll i = 0; i < n; i++) a.push_back(a[i]);

	for (ll i = 0; i < m; i++)
	{
		ll x; cin >> x;
		b.push_back(x); bsum += x;
	}

	for (ll i = 0; i < m; i++) b.push_back(b[i]);

	for (ll i = 0; i < n; i++)
	{
		ll sum = 0;
		for (ll j = 0; j < n - 1; j++)
		{
			sum += a[i + j];
			v1.push_back(sum);
		}
	}

	for (ll i = 0; i < m; i++)
	{
		ll sum = 0;
		for (ll j = 0; j < m - 1; j++)
		{
			sum += b[i + j];
			v2.push_back(sum);
		}
	}

	v1.push_back(0); v2.push_back(0);
	v1.push_back(asum); v2.push_back(bsum);
	sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());

	ll ans = 0;

	for (ll i = 0; i < v1.size(); i++)
	{
		ll cnt = upper_bound(v2.begin(), v2.end(), S - v1[i])
			- lower_bound(v2.begin(), v2.end(), S - v1[i]);

		ans += cnt;
	}

	cout << ans;
}