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
	ll n, l, w, h; cin >> n >> l >> w >> h;
	double lv = 0, rv = 1e15;
	for (ll i = 0; i < 10000; i++)
	{
		double mid = (lv + rv) / 2;
		ll cnt = (ll)(l / mid) * (ll)(w / mid) * (ll)(h / mid);
		if (cnt >= n) lv = mid;
		else rv = mid;
	}

	cout << fixed << setprecision(9) << lv;
}