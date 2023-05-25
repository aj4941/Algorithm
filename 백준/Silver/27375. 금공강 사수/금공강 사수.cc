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
	int n, k; cin >> n >> k;
	vector<pair<int, pii>> v;
	for (int i = 0; i < n; i++)
	{
		int w, s, e; cin >> w >> s >> e;
		v.push_back({ w, { s, e } });
	}

	ll ans = 0;

	for (int bit = 1; bit < (1 << n); bit++)
	{
		bool hasAns = true;
		int res = 0;
		int cnt[10][20] = { 0 };
		for (int i = 0; i < n; i++)
		{
			if (bit & (1 << i))
			{
				int w = v[i].first;
				int s = v[i].second.first, e = v[i].second.second;
				if (w == 5)
					hasAns = false;

				res += e - s + 1;
				cnt[w][s]++; cnt[w][e + 1]--;
			}
		}

		for (int W = 1; W <= 5; W++)
		{
			for (int i = 1; i <= 10; i++)
			{
				cnt[W][i] += cnt[W][i - 1];
				if (cnt[W][i] > 1)
					hasAns = false;
			}
		}

		if (res != k)
			hasAns = false;

		if (hasAns)
			ans++;
	}

	cout << ans;
}