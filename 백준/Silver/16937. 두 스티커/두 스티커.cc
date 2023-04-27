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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll r, c; cin >> r >> c;
	ll n; cin >> n;
	vector<pll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			for (ll k1 = 0; k1 < 2; k1++) for (ll k2 = 0; k2 < 2; k2++)
			{
				ll r1 = a[i].first, c1 = a[i].second;
				ll r2 = a[j].first, c2 = a[j].second;
				if (k1 == 0) swap(r1, c1);
				if (k2 == 0) swap(r2, c2);

				bool flag = false;

				if (c1 + c2 <= c && max(r1, r2) <= r) flag = true;
				if (r1 + r2 <= r && max(c1, c2) <= c) flag = true;

				if (flag)
					ans = max(ans, r1 * c1 + r2 * c2);
			}
		}
	}

	cout << ans;
}