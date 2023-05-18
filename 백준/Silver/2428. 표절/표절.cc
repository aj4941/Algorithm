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
	ll n; cin >> n;
	vector<ll> a(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] *= 10;
	}

	sort(a.begin(), a.end());

	ll j = 0;
	ll ans = 0;

	for (ll i = 0; i < n - 1; i++)
	{
		while (j < n - 1 && a[i] >= a[j + 1] * 9 / 10) j++;
		ans += j - i;
	}

	cout << ans;
	
}