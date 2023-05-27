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
int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
pii a[20][40];

pii calc(pii a, pii b)
{
	if (a.first > b.first)
		return a;
	else if (a.first < b.first)
		return b;
	else
	{
		if (a.second > b.second)
			return a;
		else
			return b;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<pair<pii, pii>> v;

	for (int i = 1; i <= 12; i++) for (int j = 1; j <= 32; j++)
		a[i][j] = pii(0, 0);

	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed; cin >> sm >> sd >> em >> ed;
		pii res = calc(a[sm][sd], pii(em, ed));
		a[sm][sd] = res;
	}

	int m = 1, d = 1;

	while (m < 13)
	{
		int nd = d + 1, nm = m;
		if (day[m] < nd)
		{
			nm++;
			nd = 1;
		}

		pii res = calc(a[nm][nd], a[m][d]);
		a[nm][nd] = res;
		m = nm, d = nd;
	}

	ll ans = 0;
	m = 3, d = 1;

	while (calc(pii(m, d), pii(11, 30)) == pii(11, 30))
	{
		pii res = a[m][d];

		if (calc(res, pii(m, d)) == pii(m, d))
		{
			cout << 0;
			return 0;
		}

		ans++;
		m = res.first, d = res.second;
	}

	cout << ans;
}