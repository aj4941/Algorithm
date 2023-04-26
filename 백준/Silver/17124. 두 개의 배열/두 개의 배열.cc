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
int res = 1e9 + 5, val = -1;

void calc(int x, int y)
{
	if (abs(x - y) < res)
	{
		res = abs(x - y);
		val = y;
	}
	else if (abs(x - y) == res)
	{
		val = y;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		vector<int> a(n), b(m), c;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++)
		{
			res = 1e9 + 5, val = -1;
			int rv = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			int lv = rv - 1;
			if (rv < b.size()) calc(a[i], b[rv]);
			if (lv >= 0) calc(a[i], b[lv]);
			c.push_back(val);
		}

		ll sum = 0;
		for (auto to : c) sum += to;

		cout << sum << "\n";
	}
}
