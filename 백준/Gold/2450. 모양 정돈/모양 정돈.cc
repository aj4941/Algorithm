#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<ll, ll, ll> ti;
ll dx[4] = { -1, 0, 1, 0 };
ll dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int cnt[5], g[5][5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}

	vector<int> p = { 1, 2, 3 };

	ll ans = 1e9;

	do {

		for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++)
			g[i][j] = 0;

		int idx = 0, c = cnt[p[idx]];
		ll sz = 0;

		for (int i = 0; i < n; i++)
		{
			g[a[i]][p[idx]]++;
			c--;

			if (a[i] != p[idx])
				sz++;
			
			if (c == 0 && idx + 1 < 3)
				c = cnt[p[++idx]];
		}

		ll res = 0;

		for (int i = 1; i <= 3; i++)
		{
			for (int j = i + 1; j <= 3; j++)
			{
				ll mn = min(g[i][j], g[j][i]);
				res += mn;
				g[i][j] -= mn; g[j][i] -= mn;
				sz -= 2 * mn;
			}
		}

		res += sz / 3 * 2;

		ans = min(ans, res);

	} while (next_permutation(p.begin(), p.end()));

	cout << ans;
}