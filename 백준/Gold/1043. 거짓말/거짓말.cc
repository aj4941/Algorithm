#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 10987654321
const ll N = 100;
ll p[N];
bool cache[N];

ll find(ll x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, c; cin >> n >> m;
	for (ll i = 1; i <= n; i++) p[i] = i;
	cin >> c;
	vector<vector<ll>> v;
	vector<ll> a;

	for (ll i = 0; i < c; i++)
	{
		ll x; cin >> x;
		a.push_back(x);
	}

	for (ll i = 0; i < m; i++)
	{
		ll c; cin >> c;
		v.push_back({});
		for (ll j = 0; j < c; j++)
		{
			ll x; cin >> x;
			v.back().push_back(x);
		}

		for (ll i = 1; i < v.back().size(); i++)
		{
			ll x = find(v.back()[i]), y = find(v.back()[i - 1]);
			p[x] = y;
		}
	}

	for (auto to : a) cache[find(to)] = true;

	ll ans = 0;

	for (auto &to : v)
	{
		if (cache[find(to.front())] == false)
			ans++;
	}

	cout << ans;
}