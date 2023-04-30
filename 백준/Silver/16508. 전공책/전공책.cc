#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 30;
ll cnt[N][N], cost[N], have[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	ll n; cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> cost[i];
		string t; cin >> t;
		for (auto to : t) 
			cnt[i][to - 'A']++;
	}

	ll ans = 1e9;

	for (ll bit = 1; bit < (1ll << n); bit++)
	{
		ll cur_cost = 0;
		memset(have, 0, sizeof have);

		for (ll i = 0; i < n; i++)
		{
			if (bit & (1ll << i))
			{
				cur_cost += cost[i];
				for (ll j = 0; j < 26; j++)
					have[j] += cnt[i][j];
			}
		}

		bool hasAns = true;

		for (auto to : s)
		{
			ll idx = to - 'A';
			have[idx]--;
			if (have[idx] < 0)
				hasAns = false;
		}

		if (hasAns)
			ans = min(ans, cur_cost);
	}

	if (ans == 1e9) ans = -1;
	cout << ans;
}