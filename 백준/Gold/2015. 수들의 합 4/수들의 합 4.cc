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
	vector<ll> a(n + 1), val(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];

	map<ll, ll> cnt; cnt[0] = 1;

	ll sum = 0;

	for (ll i = 1; i <= n; i++)
	{
		sum += a[i];
		cnt[sum]++; val[i] = sum;
	}

	ll ans = 0;

	for (ll i = n; i >= 1; i--)
	{
		ans += cnt[val[i] - k];
		if (k == 0) ans--;
		cnt[val[i]]--;
	}

	cout << ans;
}