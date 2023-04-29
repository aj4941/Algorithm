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
	ll n, k; cin >> n >> k;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	vector<pll> v;

	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++)		
		v.push_back({ a[i] * b[j], j });

	sort(v.rbegin(), v.rend());

	ll ans = -1;
	map<ll, ll> mp;

	for (auto to : v)
	{
		ll idx = to.second;
		if (mp[idx] == 0)
		{
			mp[idx] = 1;
			k--;
		}

		if (k < 0)
		{
			ans = to.first;
			break;
		}
	}

	cout << ans;
}