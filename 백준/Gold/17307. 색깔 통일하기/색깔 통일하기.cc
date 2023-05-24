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
ll n, c;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	 cin >> n >> c;
	vector<ll> a(n + 5), l(n + 5), r(n + 5);
	for (ll i = 1; i <= n; i++) cin >> a[i];

	for (ll i = 2; i <= n; i++)
	{
		l[i] = l[i - 1];
		ll d = (a[i - 1] - a[i] + c) % c;
		l[i] += d;
	}

	for (ll i = n - 1; i >= 1; i--)
	{
		r[i] = r[i + 1];
		ll d = (a[i + 1] - a[i] + c) % c;
		r[i] += d;
	}

	ll ans = 1e18;
	ll idx = -1;

	for (ll i = 1; i <= n; i++)
	{
		if (max(l[i], r[i]) < ans)
		{
			ans = max(l[i], r[i]);
			idx = i;
		}
	}

	cout << idx << "\n";
	cout << ans;
}