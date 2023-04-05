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
ll n, m, k;
const ll N = 200;
bool gold[N];
vector<pll> g[N];
bool cache[N][1 << 16];
vector<ll> tmp;
ll g_idx[N];

ll count(ll bit)
{
	ll res = 0;
	for (ll i = 0; i < 20; i++)
	{
		if (bit & (1ll << i))
			res++;
	}

	return res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int x; cin >> x; x--;
		gold[x] = true;
		tmp.push_back(x);
	}

	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < k; i++) g_idx[tmp[i]] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}

	cache[0][0] = true;
	queue<pll> q; q.push({ 0, 0 });

	if (gold[0]) 
	{
		cache[0][1 << g_idx[0]] = true;
		q.push({ 0, (1 << g_idx[0]) });
	}

	while (!q.empty())
	{
		auto to = q.front(); q.pop();
		ll v = to.first, bit = to.second;
		ll cnt = count(bit);

		for (auto &to : g[v])
		{
			ll nv = to.first, c = to.second;
			if (c < cnt) continue;

			ll nbit = gold[nv] ? (bit | (1 << g_idx[nv])) : bit;
			if (!cache[nv][nbit])
			{
				q.push({ nv, nbit });
				cache[nv][nbit] = true;
			}

			if (!cache[nv][bit])
			{
				q.push({ nv, bit });
				cache[nv][bit] = true;
			}
		}
	}

	ll ans = 0;
	
	for (ll bit = 0; bit < (1ll << k); bit++)
	{
		if (cache[0][bit])
			ans = max(ans, count(bit));
	}

	cout << ans;
}