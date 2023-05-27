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
	int n; cin >> n;
	vector<pll> a(n);
	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		sum += a[i].second;
	}

	sort(a.begin(), a.end());

	ll pos = -1;
	ll mid = (sum + 1) / 2;
	ll cur = 0;

	for (ll i = 0; i < n; i++)
	{
		cur += a[i].second;
		if (cur >= mid)
		{
			pos = a[i].first;
			break;
		}
	}

	cout << pos;
}