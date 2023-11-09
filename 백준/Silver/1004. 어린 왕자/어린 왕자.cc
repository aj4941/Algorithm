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
	ll t; cin >> t;
	while (t--)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll n; cin >> n;
		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			ll cx, cy, r; cin >> cx >> cy >> r;
			ll cnt = 0;
			if (sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy))
				<= r) cnt++;
			if (sqrt((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy))
				<= r) cnt++;
			if (cnt == 1)
				ans++;
		}
		cout << ans << "\n";
	}
}