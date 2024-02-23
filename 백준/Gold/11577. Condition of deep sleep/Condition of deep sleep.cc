#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, k; cin >> n >> k;
	vector<ll> a(n + 5), pxor(n + 5);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		pxor[i] = a[i - 1] ^ a[i];
	}

	ll ans = 0;

	for (ll i = 1; i <= n; i++)
	{
		if (i + k - 1 > n) break;
		if (pxor[i])
		{
			pxor[i] ^= 1;
			pxor[i + k] ^= 1; ans++;
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		if (pxor[i])
			ans = -1;
	}

	if (ans == -1) cout << "Insomnia";
	else cout << ans;
}