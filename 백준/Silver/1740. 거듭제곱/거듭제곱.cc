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
const ll N = 42;
ll p[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll idx = 0, mul = 1;

	while (idx < N)
	{
		p[idx++] = mul;
		mul *= 3;
	}

	ll n; cin >> n;
	ll ans = 0;

	for (ll i = 40; i >= 0; i--)
	{
		if (n & (1ll << i))
		{
			n -= (1ll << i);
			ans += p[i];
		}
	}

	cout << ans;
}