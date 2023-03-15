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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, l, r, x; cin >> n >> l >> r >> x;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;

	for (ll num = 1; num < (1ll << n); num++)
	{
		ll sum = 0, mn = 1e10, mx = -1e10;
		for (ll i = 0; i < n; i++)
		{
			if (num & (1ll << i))
			{
				sum += a[i];
				mn = min(mn, a[i]); mx = max(mx, a[i]);
			}
		}

		if (l <= sum && sum <= r && mx - mn >= x)
			ans++;
	}

	cout << ans;
}