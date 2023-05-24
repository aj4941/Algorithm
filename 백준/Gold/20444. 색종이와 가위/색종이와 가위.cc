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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, k; cin >> n >> k;
	ll l = n / 2, r = n + 1; // [l, r)

	while (l + 1 < r)
	{
		ll mid = (l + r) / 2;
		ll x = mid, y = n - mid;
		ll res = (x + 1) * (y + 1);
		if (res < k) r = mid;
		else l = mid;
	}

	ll x = l, y = n - l;
	if ((x + 1) * (y + 1) == k) cout << "YES";
	else cout << "NO";
}