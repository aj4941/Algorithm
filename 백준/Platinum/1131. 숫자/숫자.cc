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
const ll N = 4000002;
ll cache[N], g[N], dp[N];
ll a, b, k;
vector<ll> stk;
vector<vector<ll>> cycle;

ll mpow(ll a, ll x)
{
	if (x == 0) return 1;
	ll res = mpow(a, x / 2);
	res = res * res;
	if (x % 2) res = res * a;

	return res;
}

ll calc(ll x)
{
	ll res = 0;
	while (x > 0)
	{
		res += mpow(x % 10, k);
		x /= 10;
	}

	return res;
}

void dfs(ll v)
{
	cache[v] = 1;
	stk.push_back(v);
	ll nv = g[v];
	if (cache[nv] == 1) // v -> nv
	{
		deque<ll> chk;
		cycle.push_back({});
		while (stk.back() != nv)
		{
			cycle.back().push_back(stk.back());
			chk.push_front(stk.back());
			stk.pop_back();
		}
		cycle.back().push_back(stk.back());
		chk.push_front(stk.back());
		stk.pop_back();

		while (chk.size())
		{
			stk.push_back(chk.front());
			chk.pop_front();
		}
	}
	else if (cache[nv] == 0)
		dfs(nv);

	cache[v] = 2;
	stk.pop_back();
}

ll solve(ll x)
{
	ll& ret = dp[x];
	if (ret != -1) return ret;
	return ret = min(x, solve(g[x]));
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> k; 
	for (ll i = 1; i < N; i++) g[i] = calc(i);

	for (ll i = 1; i < N; i++)
	{
		if (cache[i] == 2) continue;
		dfs(i);
	}


	memset(dp, -1, sizeof dp);

	for (ll i = 0; i < cycle.size(); i++)
	{
		sort(cycle[i].begin(), cycle[i].end());
		for (auto to : cycle[i])
			dp[to] = cycle[i][0];
	}

	for (ll i = 1; i < N; i++) solve(i);

	ll ans = 0;

	for (ll i = a; i <= b; i++)
		ans += dp[i];

	cout << ans;
}