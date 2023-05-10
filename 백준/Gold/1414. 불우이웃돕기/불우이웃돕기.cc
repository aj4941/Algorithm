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
const int N = 100002;
vector<pair<int, pii>> edge;
int n;
int p[N];

int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int calc(char c)
{
	if (c == '0') return 0;
	if ('a' <= c && c <= 'z')
		return c - 'a' + 1;
	else
		return c - 'A' + 27;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	ll ans = 0;

	for (int i = 1; i <= n; i++) p[i] = i;

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int m = s.size();
		for (int j = 0; j < m; j++)
		{
			int w = calc(s[j]);
			if (w != 0)
			{
				ans += w;
				edge.push_back({ w, { i + 1, j + 1 } });
			}
		}
	}

	sort(edge.begin(), edge.end());

	for (auto to : edge)
	{
		int w = to.first;
		int u = to.second.first, v = to.second.second;
		u = find(u), v = find(v);
		if (u == v) continue;
		ans -= w; p[u] = v;
	}

	bool hasAns = true;

	for (int i = 1; i <= n - 1; i++)
	{
		if (find(i) != find(n))
			hasAns = false;
	}

	if (hasAns) cout << ans;
	else cout << -1;
}