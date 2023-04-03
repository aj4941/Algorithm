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
const int N = 200002;
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
	while (true) 
	{
		vector<pair<int, pii>> edge;
		int m, n; cin >> m >> n;
		if (m == 0 && n == 0) break;
		ll ans = 0;
		for (int i = 1; i <= m; i++) p[i] = i;

		for (int i = 0; i < n; i++)
		{
			int u, v, w; cin >> u >> v >> w; u++; v++;
			edge.push_back({ w, { u, v } });
			ans += w;
		}

		sort(edge.begin(), edge.end());

		ll use = 0;

		for (auto to : edge)
		{
			int w = to.first;
			int u = to.second.first, v = to.second.second;
			int nu = find(u), nv = find(v);
			if (nu == nv) continue;
			p[nu] = nv; use += w;
		}

		cout << ans - use << "\n";
	}
}