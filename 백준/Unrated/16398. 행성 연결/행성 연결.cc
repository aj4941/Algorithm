#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1002;
ll c[N][N], n;
vector<tl> edge;
ll p[N];

int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> c[i][j];
		edge.push_back({ c[i][j], i + 1, j + 1 });
	}

	sort(edge.begin(), edge.end());

	ll ans = 0;

	for (auto to : edge)
	{
		ll w = get<0>(to), u = get<1>(to), v = get<2>(to);
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
		ans += w;
	}

	cout << ans;
}