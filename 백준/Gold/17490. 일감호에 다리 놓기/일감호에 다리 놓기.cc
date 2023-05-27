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
const int N = 1000002;
int p[N];

int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, k; cin >> n >> m >> k;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n + 1; i++) p[i] = i;

	vector<pair<ll, pii>> edge;
	map<pii, int> mp;

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		mp[{ u, v }] = 1;
	}

	if (m <= 1)
	{
		cout << "YES";
		return 0;
	}

	for (int i = 1; i <= n; i++) 
	{
		int ni = i + 1 > n ? 1 : i + 1;
		if (mp.count({ i, ni })) continue;
		if (mp.count({ ni, i })) continue;
		edge.push_back({ 0, { i, ni } });
	}

	for (int i = 1; i <= n; i++)
		edge.push_back({ a[i], { i, n + 1 } });

	sort(edge.begin(), edge.end());

	for (auto to : edge)
	{
		int u = to.second.first, v = to.second.second;
		int w = to.first;
		if (w != 0) break;
		u = find(u), v = find(v); p[u] = v;
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (find(i) == i)
			cnt++;
	}

	if (cnt == 1)
	{
		cout << "YES";
		return 0;
	}

	ll res = 0;

	for (auto to : edge)
	{
		int u = to.second.first, v = to.second.second;
		u = find(u); v = find(v);

		if (u == v) continue;
		res += to.first; p[u] = v;
	}

	bool hasAns = true;

	if (k < res) 
		hasAns = false;

	if (hasAns) cout << "YES";
	else cout << "NO";
}