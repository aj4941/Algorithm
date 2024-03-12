#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll P, B, N;

ll mpow(ll a, ll x)
{
	if (x == 0)
		return 1;
	ll res = mpow(a, x / 2);
	res = res * res % P;
	if (x % 2) res = res * a % P;
	return res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (cin >> P >> B >> N)
	{
		map<ll, ll> mp;
		ll t = sqrt(P);
		for (ll x = 0; x <= t; x++)
		{
			ll res = mpow(B, x * t);
			if (!mp.count(res)) mp[res] = x;
			else mp[res] = min(mp[res], x);
		}

		ll ans = 1e18;

		for (ll y = 0; y <= t; y++)
		{
			ll res = mpow(mpow(B, y), P - 2) * N % P;
			if (mp.count(res))
			{
				ll x = mp[res];
				ans = min(ans, x * t + y);
			}
		}

		if (ans == 1e18)
			cout << "no solution" << "\n";
		else
			cout << ans << "\n";
	}

}