#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 10987654321

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;

	for (ll bit = 1; bit < (1ll << n); bit++)
	{
		ll cnt = 0, w = 1;
		for (ll i = 0; i < n; i++)
		{
			if (bit & (1ll << i))
			{
				w *= a[i];
				cnt++;
			}
		}

		if (cnt % 2) ans += m / w;
		else ans -= m / w;
	}

	cout << ans;
}