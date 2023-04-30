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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 20;
ll a[N], color[N], cache[N];
ll value[3];
vector<ll> g[N];
ll ans = 1e9;

void dfs(ll v)
{
	cache[v] = 1;
	value[color[v]] += a[v];
	for (ll nv : g[v])
	{
		if (cache[nv]) continue;
		if (color[v] == color[nv]) dfs(nv);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];

	for (ll i = 1; i <= n; i++)
	{
		ll k; cin >> k;
		for (ll j = 1; j <= k; j++)
		{
			ll x; cin >> x;
			g[i].push_back(x);
		}
	}

	for (ll bit = 1; bit < (1ll << n) - 1; bit++)
	{
		for (ll i = 0; i < n; i++)
		{
			if (bit & (1ll << i))
				color[i + 1] = 1;
			else
				color[i + 1] = 2;
		}

		ll cnt = 0;
		value[1] = 0, value[2] = 0;
		memset(cache, 0, sizeof cache);

		for (ll i = 1; i <= n; i++)
		{
			if (!cache[i])
			{
				dfs(i);
				cnt++;
			}
		}

		if (cnt != 2 || value[1] == 0 || value[2] == 0) continue;
		ans = min(ans, abs(value[1] - value[2]));
	}

	if (ans == 1e9) ans = -1;
	cout << ans;
}