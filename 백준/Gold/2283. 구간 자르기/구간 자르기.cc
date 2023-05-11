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
const ll N = 2000002;
ll cnt[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, k; cin >> n >> k;
	for (ll i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		cnt[x]++; cnt[y]--;
	}

	for (ll i = 1; i < N; i++)
		cnt[i] += cnt[i - 1];

	ll l = 0, r = 0;
	ll res = cnt[0];
	pll ans = pll(0, 0);

	while (true)
	{
		if (res == k)
		{
			ans = pll(l, r + 1);
			break;
		}

		if (res > k)
		{
			res -= cnt[l++];
			if (l > r)
			{
				r = l;
				res = cnt[l];
			}
		}
		else
		{
			res += cnt[++r];
			if (r == N)
				break;
		}
	}

	cout << ans.first << ' ' << ans.second;
}